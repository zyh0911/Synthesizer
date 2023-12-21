#include "coarsening.hpp"

#include <algorithm>
#include <numeric>
#include <time.h>
#include <utility>
#include <vector>

// main function of EC coarsening
std::vector<std::pair<int, std::vector<int> *>> *
EC_Coarsening::Coarsening(Hypergraph *graph, result *inst,
                          std::vector<double> &spaceLimit, bool restricted) {
  std::vector<double> nodeWeights = computeNodeWeights(graph);
  std::vector<int> nds;
  std::vector<bool> ndsRemain(graph->getAllNodes().size(), true);
  auto coarsenInfo = new std::vector<std::pair<int, std::vector<int> *>>();
  int nodeNum = graph->getNodeNum();

  nds.reserve(graph->getAllNodes().size());
  for (int i = 0; i < graph->getAllNodes().size(); i++) {
    if (!graph->getNodeExistOf(i))
      ndsRemain[i] = false;
    nds.push_back(i);
  }

  std::random_device rd;
  // std::mt19937 g(rd());
  // std::shuffle(nds.begin(), nds.end(), g);
  std::random_shuffle(nds.begin(), nds.end());

  for (auto it = nds.begin(); it != nds.end(); it++) {
    if (!ndsRemain[*it])
      continue;

    int idx = chooseMaxWeight(graph, inst, nodeWeights, spaceLimit, ndsRemain,
                              *it, restricted);
    ndsRemain[*it] = false;

    if (*it != idx) {
      ndsRemain[idx] = false;

      std::vector<int> *nodeVec = new std::vector<int>();
      nodeVec->push_back(*it);
      nodeVec->push_back(idx);

      auto info = graph->coarseNodes(nodeVec);
      coarsenInfo->push_back(info);

      nodeNum--;
    }
  }

  graph->setNodeNum(nodeNum);
  return coarsenInfo;
}

// return vector of the weight of each node
// node weight: the sum of weights of all the edges connected to a node
std::vector<double> EC_Coarsening::computeNodeWeights(Hypergraph *graph) {
  std::vector<double> nodeWeights;
  nodeWeights.reserve(graph->getAllNodes().size());

  for (int i = 0; i < graph->getAllNodes().size(); i++) {
    double w = DBL_MAX;

    if (graph->getNodeExistOf(i)) {
      std::vector<int> &edges = graph->getEdgesOf(i);

      for (int j = 0; j < edges.size(); j++) {
        w += graph->getEdgeWeightOf(edges[j]);
      }
    }

    nodeWeights.push_back(w);
  }

  return nodeWeights;
}

// return neighbor node of n1 with maximum weight
int EC_Coarsening::chooseMaxWeight(Hypergraph *graph, result *inst,
                                   std::vector<double> &nodeWeights,
                                   std::vector<double> &spaceLimit,
                                   std::vector<bool> &ndsRemain, int n1,
                                   bool restricted) {
  // edges connected to node n1
  std::vector<int> &edges = graph->getEdgesOf(n1);
  int nMax = n1, part = inst->getPartitionOf(n1);
  double maxWeight = 0, weight = graph->getNodeWeightOf(n1);

  for (auto it = edges.begin(); it != edges.end(); it++) {
    std::vector<int> &neigs = graph->getNodesOf(*it);
    int count = graph->getNodeNumOf(*it);

    if (count == 1)
      continue;

    for (auto itt = neigs.begin(); itt != neigs.begin() + count; itt++) {
      if (restricted && inst->getPartitionOf(*itt) != part)
        continue;

      if (ndsRemain[*itt] && nodeWeights[*itt] > maxWeight &&
          graph->getNodeWeightOf(*itt) + weight <= spaceLimit[part]) {
        maxWeight = nodeWeights[*itt];
        nMax = *itt;
      }
    }
  }

  return nMax;
}

// main function of HEC coarsening
// MHEC for "modified" HEC
std::vector<std::pair<int, std::vector<int> *>> *
HEC_Coarsening::Coarsening(Hypergraph *graph, result *inst,
                           std::vector<double> &spaceLimit, bool restricted,
                           bool MHEC) {
  std::vector<int> sortedEdge = sortEdge(graph);
  std::vector<bool> nodesRemain(graph->getAllNodes().size(), true);
  auto coarsenInfo = new std::vector<std::pair<int, std::vector<int> *>>();
  int nodeNum = graph->getNodeNum();

  for (auto e_it = sortedEdge.begin(); e_it != sortedEdge.end(); e_it++) {
    std::vector<int> &nodesConnected = graph->getNodesOf(*e_it);
    int count = graph->getNodeNumOf(*e_it);
    int part = inst->getPartitionOf(nodesConnected[0]);

    // check if "preserve initial partitioning" is needed and conformed
    // check if all connected nodes in the edge have not been picked
    if ((!restricted ||
         (restricted && preservePartition(inst, nodesConnected, count))) &&
        nodesNotMatched(nodesConnected, count, nodesRemain) &&
        graph->sizeUnderLimit(nodesConnected, count, spaceLimit[part])) {
      std::vector<int> *nds = new std::vector<int>();

      for (auto it = nodesConnected.begin();
           it != nodesConnected.begin() + count; it++) {
        nds->push_back(*it);
        nodesRemain[*it] = false;
      }

      auto info = graph->coarseNodes(nds);
      coarsenInfo->push_back(info);

      graph->setEdgeExistOf(*e_it, false);
      nodeNum = nodeNum - count + 1;
    }
  }

  if (MHEC) {
    for (auto e_it = sortedEdge.begin(); e_it != sortedEdge.end(); e_it++) {
      if (!graph->getEdgeExistOf(*e_it))
        continue;

      std::vector<int> &nodesConnected = graph->getNodesOf(*e_it);
      std::vector<int> *unmatchedNodes0 = new std::vector<int>();
      std::vector<int> *unmatchedNodes1 = new std::vector<int>();
      int count = graph->getNodeNumOf(*e_it);
      double weight0 = 0, weight1 = 0;

      for (auto it = nodesConnected.begin();
           it != nodesConnected.begin() + count; it++) {
        if (nodesRemain[*it]) {
          if (inst->getPartitionOf(*it) == 0) {
            unmatchedNodes0->push_back(*it);
            weight0 += graph->getNodeWeightOf(*it);
          } else {
            unmatchedNodes1->push_back(*it);
            weight1 += graph->getNodeWeightOf(*it);
          }
        }
      }

      if (!unmatchedNodes0->empty() && weight0 <= spaceLimit[0]) {
        auto info = graph->coarseNodes(unmatchedNodes0);
        coarsenInfo->push_back(info);
        nodeNum = nodeNum - unmatchedNodes0->size() + 1;
        for (auto it = unmatchedNodes0->begin(); it != unmatchedNodes0->end();
             it++)
          nodesRemain[*it] = false;
      } else
        delete unmatchedNodes0;

      if (!unmatchedNodes1->empty() && weight1 <= spaceLimit[1]) {
        auto info = graph->coarseNodes(unmatchedNodes1);
        coarsenInfo->push_back(info);
        nodeNum = nodeNum - unmatchedNodes1->size() + 1;
        for (auto it = unmatchedNodes1->begin(); it != unmatchedNodes1->end();
             it++)
          nodesRemain[*it] = false;
      } else
        delete unmatchedNodes1;
    }
  }
  graph->setNodeNum(nodeNum);

  return coarsenInfo;
}

bool cmp(const sort_edge_info &a, const sort_edge_info &b) {
  if (a.weight != b.weight)
    return a.weight > b.weight;
  else
    return a.nodeNum < b.nodeNum;
}

// return sorted edge idx with respect to weight and size
std::vector<int> HEC_Coarsening::sortEdge(Hypergraph *graph) {
  std::vector<sort_edge_info> infos;
  for (int i = 0; i < graph->getEdgeNum(); i++) {
    if (graph->getEdgeExistOf(i) && graph->getNodeNumOf(i) != 1)
      infos.push_back(
          sort_edge_info(i, graph->getNodeNumOf(i), graph->getEdgeWeightOf(i)));
  }

  sort(infos.begin(), infos.end(), cmp);

  std::vector<int> edgeIdxs;
  edgeIdxs.reserve(infos.size());
  for (auto it = infos.begin(); it != infos.end(); it++)
    edgeIdxs.push_back(it->idx);

  return edgeIdxs;
}

// return true if all node indexes in the first vector is not matched
// otherwise return false
bool HEC_Coarsening::nodesNotMatched(std::vector<int> &nodesConnected,
                                     int count,
                                     std::vector<bool> &nodesRemain) {
  for (auto it = nodesConnected.begin(); it != nodesConnected.begin() + count;
       it++) {
    if (!nodesRemain[*it])
      return false;
  }

  return true;
}

// return true if the whole edge belongs to the same partition
bool HEC_Coarsening::preservePartition(result *inst,
                                       std::vector<int> &nodesConnected,
                                       int count) {
  int part = inst->getPartitionOf(nodesConnected[0]);

  for (auto it = nodesConnected.begin() + 1;
       it != nodesConnected.begin() + count; it++) {
    if (inst->getPartitionOf(*it) != part)
      return false;
  }

  return true;
}

std::vector<std::pair<int, std::vector<int> *>> *
Coarsen::Coarsening(Hypergraph *graph, result *inst,
                    std::vector<double> &spaceLimit, bool restricted,
                    std::string &scheme) {
  if (scheme == "HEC")
    return HEC.Coarsening(graph, inst, spaceLimit, restricted, false);
  else if (scheme == "MHEC")
    return HEC.Coarsening(graph, inst, spaceLimit, restricted, true); // MHEC
  else
    return EC.Coarsening(graph, inst, spaceLimit, restricted);
}