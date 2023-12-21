#include "refinement.hpp"

// move node in gain bucket data structure
void FM::updateGain(int idx, int delta) {
  int gain = nodePointers[idx].first, bucketIdx = maxGain + gain;

  gainBucket[bucketIdx].erase(nodePointers[idx].second);
  gainBucket[bucketIdx + delta].push_back(idx);
  nodePointers[idx].first = gain + delta;
  nodePointers[idx].second = --gainBucket[bucketIdx + delta].end();
}

void FM::getEdgePartitionStatus() {
  for (int i = 0; i < graph->getAllEdges().size(); i++) {
    if (!graph->getEdgeExistOf(i) || graph->getNodeNumOf(i) == 1)
      continue;

    vector<int> &nds = graph->getNodesOf(i);
    int count = graph->getNodeNumOf(i);

    for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
      if (inst->getPartitionOf(*itt) == 0)
        pv[0][i]++;
      else
        pv[1][i]++;
    }
  }
}

int FM::getMaxGain() {
  int maxGain = 0;

  for (int i = 0; i < graph->getAllNodes().size(); i++) {
    if (!graph->getNodeExistOf(i))
      continue;

    int edgeNum = graph->getEdgesOf(i).size();
    if (maxGain < edgeNum)
      maxGain = edgeNum;
  }

  return maxGain;
}

void FM::buildGainBucketDS() {
  for (int i = 0; i < graph->getAllNodes().size(); i++) {
    if (!graph->getNodeExistOf(i))
      continue;

    vector<int> &eds = graph->getEdgesOf(i);
    int part = inst->getPartitionOf(i), partTo = part == 0 ? 1 : 0, gain = 0;

    for (auto it = eds.begin(); it != eds.end(); it++) {
      if (graph->getEdgeExistOf(*it) && graph->getNodeNumOf(*it) != 1) {
        if (pv[part][*it] == 1)
          gain++;
        else if (pv[partTo][*it] == 0)
          gain--;
      }
    }

    gainBucket[maxGain + gain].push_back(i);
    nodePointers[i] = make_pair(gain, --gainBucket[maxGain + gain].end());
  }
}

void FM::revertMoves() {
  for (auto it = revertBuf.rbegin(); it != revertBuf.rend(); it++) {
    updateDataStructure(*it);
  }
}

void FM::updateDataStructure(int n_idx) {
  vector<int> &eds = graph->getEdgesOf(n_idx);
  int part = inst->getPartitionOf(n_idx), partTo = part == 0 ? 1 : 0;

  for (auto it = eds.begin(); it != eds.end(); it++) {
    vector<int> &nds = graph->getNodesOf(*it);
    int count = graph->getNodeNumOf(*it);

    if (count == 1)
      continue;

    if (pv[part][*it] == 1) {
      if (pv[partTo][*it] == 1) {
        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          updateGain(*itt, -2);
        }
      } else {
        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          if (inst->getPartitionOf(*itt) == part) {
            updateGain(*itt, -2);
          } else {
            updateGain(*itt, -1);
          }
        }
      }
    } else if (pv[part][*it] == 2) {
      if (pv[partTo][*it] == 0) {
        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          updateGain(*itt, 2);

          if (nodePointers[*itt].first > tmpMaxGain && !locked[*itt]) {
            tmpMaxGain = nodePointers[*itt].first;
          }
        }
      } else {
        if (pv[partTo][*it] == 1) {
          for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
            if (inst->getPartitionOf(*itt) == partTo) {
              updateGain(*itt, -1);
              break;
            }
          }
        }

        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          if (inst->getPartitionOf(*itt) == part && *itt != n_idx) {
            updateGain(*itt, 1);

            if (nodePointers[*itt].first > tmpMaxGain && !locked[*itt]) {
              tmpMaxGain = nodePointers[*itt].first;
            }

            break;
          }
        }
      }
    } else {
      if (pv[partTo][*it] == 0) {
        updateGain(n_idx, 1);
        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          updateGain(*itt, 1);
          if (nodePointers[*itt].first > tmpMaxGain && !locked[*itt]) {
            tmpMaxGain = nodePointers[*itt].first;
          }
        }
      } else if (pv[partTo][*it] == 1) {
        for (auto itt = nds.begin(); itt != nds.begin() + count; itt++) {
          if (inst->getPartitionOf(*itt) == partTo) {
            updateGain(*itt, -1);
            break;
          }
        }
      }
    }

    pv[part][*it]--;
    pv[partTo][*it]++;
  }

  partSize[partTo] += graph->getNodeWeightOf(n_idx);
  partSize[part] -= graph->getNodeWeightOf(n_idx);
  inst->setPartitionOf(n_idx, partTo);
}

int FM::selectVictimNode() {
  int n_idx = -1;

  while (noImprove <= k && tmpMaxGain > (-1) * maxGain) {
    int bucketIdx = maxGain + tmpMaxGain;

    for (auto it = gainBucket[bucketIdx].begin();
         it != gainBucket[bucketIdx].end(); it++) {
      if (locked[*it])
        continue;

      int part = inst->getPartitionOf(*it), partTo = part == 0 ? 1 : 0;

      if (partSize[partTo] + graph->getNodeWeightOf(*it) > spaceLimit[partTo])
        continue;

      locked[*it] = true;
      n_idx = *it;
      break;
    }

    if (n_idx == -1)
      tmpMaxGain--;
    else {
      // node found
      // if the move increase cut size, push it in revert buffer
      if (nodePointers[n_idx].first < 0 || debt < 0) {
        debt += (nodePointers[n_idx].first);

        // save gain bucket data structure
        if (debt < 0) {
          revertBuf.push_back(n_idx);
          noImprove++;
        } else {
          revertBuf.clear();
          noImprove = 0;
          debt = 0;
        }
      }

      break;
    }
  }

  return n_idx;
}

void FM::reset() {
  revertBuf.clear();
  tmpMaxGain = maxGain;
  noImprove = 0;
  debt = 0;

  for (int i = 0; i < locked.size(); i++)
    locked[i] = false;
}

void FM::Partition() {
  // calculate number of nodes in each edge in each partition
  getEdgePartitionStatus();

  // build gain bucket data structure
  buildGainBucketDS();

  // implement FM algo
  for (int i = 0; i < pass; i++) {
    while (true) {
      int n_idx = selectVictimNode();

      // no available node found
      if (n_idx == -1)
        break;

      // update gain to neighboring nodes
      updateDataStructure(n_idx);
    }

    // revert previous moves to the smallest cut size
    if (debt < 0) {
      revertMoves();
    }

    reset();
  }

  inst->setp0size(partSize[0]);
  inst->setp1size(partSize[1]);

  inst->computePartitionScore(graph);
}