#include "result.hpp"

#include <map>
#include <unordered_map>
#include <utility>

//////////////////////////////////////////////////////////////////////
//////////////////////// result ///////////////////////////////////
//////////////////////////////////////////////////////////////////////

double result::getp0size() { return p0size; }

double result::getp1size() { return p1size; }

double result::getPartitionScore() { return partScore; }

int result::getPartitionOf(int idx) { return part[idx]; }

void result::setp0size(double size) { p0size = size; }

void result::setp1size(double size) { p1size = size; }

void result::setPartitionScore(double size) { partScore = size; }

void result::setPartitionOf(int idx, int p) { part[idx] = p; }

// count and set hypergraph partition score
void result::computePartitionScore(Hypergraph *g) {
  double score = DBL_MIN;

  for (int e_id = 0; e_id < g->getEdgeNum(); e_id++) {
    if (!g->getEdgeExistOf(e_id))
      continue;

    std::vector<int> &nds = g->getNodesOf(e_id);
    int count = g->getNodeNumOf(e_id);
    int part = getPartitionOf(nds[0]);

    for (auto it = nds.begin(); it != nds.begin() + count; it++) {
      if (getPartitionOf(*it) != part) {
        score += g->getEdgeWeightOf(e_id);
        break;
      }
    }
  }

  setPartitionScore(score);
}

void result::mapPartition(
    std::vector<std::pair<int, std::vector<int> *>> *coarsenInfo) {
  for (auto it = coarsenInfo->begin(); it != coarsenInfo->end(); it++) {
    auto nds = it->second;
    int part = getPartitionOf(it->first);

    for (auto itt = nds->begin(); itt != nds->end(); itt++)
      setPartitionOf(*itt, part);
  }
}

bool result::ggp(Hypergraph *graph, std::vector<double> &spaceLimit) {
  std::random_device rd;
  std::mt19937 gen(rd());

  int hnodeSize = graph->getAllNodes().size(), num = 5;

  while (num-- > 0) {
    std::vector<bool> nodesPicked(graph->getAllNodes().size(), false);
    std::queue<int> q;
    double p0size = 0, p1size = getp1size();
    int firstNode = gen() % hnodeSize;

    while (!graph->getNodeExistOf(firstNode)) {
      firstNode++;
      if (firstNode == hnodeSize)
        firstNode = 0;
    }
    q.push(firstNode);
    nodesPicked[firstNode] = true;

    while (p1size > spaceLimit[1] / 2) {
      // make sure there always exists node in BFS queue
      int top;
      if (!q.empty()) {
        top = q.front();
        q.pop();
      } else {
        int count = 0;
        top = gen() % hnodeSize;
        for (; count < hnodeSize; count++) {
          if (!nodesPicked[top] && graph->getNodeExistOf(top))
            break;
          top = (top + 1) % hnodeSize;
        }
        if (count == hnodeSize)
          break;
        nodesPicked[top] = true;
      }

      // BFS
      std::vector<int> &edges = graph->getEdgesOf(top);
      for (auto it = edges.begin(); it != edges.end(); it++) {
        std::vector<int> &nodes = graph->getNodesOf(*it);
        int c = graph->getNodeNumOf(*it);
        for (auto itt = nodes.begin(); itt != nodes.begin() + c; itt++) {
          if (!nodesPicked[*itt] && getPartitionOf(*itt) == 1) {
            nodesPicked[*itt] = true;
            q.push(*itt);
          }
        }
      }

      // check if the shift fit the spacing limitations
      double weight = graph->getNodeWeightOf(top);
      if (!(p0size + weight > spaceLimit[0])) {
        p0size += weight;
        p1size -= weight;
        setPartitionOf(top, 0);
      }
    }

    setp0size(p0size);
    setp1size(p1size);
    // if (graph->getp2size() > spaceLimit[1]) enableDieSizeLimit(graph,
    // spaceLimit);
    if (p1size <= spaceLimit[1])
      return true;

    this->~result();
    new (this) result(graph);
  }

  return false;
}

class NodeWeightStorage {
public:
  int popMaxWeightNode() {

    auto maxNodeIt = nodeMap.rbegin();
    int maxNodeId = maxNodeIt->first;
    nodeMap.erase(maxNodeIt->first);
    return maxNodeId;
  }

  void addNode(int nodeId) {
    if (nodeMap.find(nodeId) != nodeMap.end()) {
      addWeight(nodeId);
    } else {
      nodeMap[nodeId] = 1;
      sortByWeight();
    }
  }

  void addWeight(int nodeId) {
    auto it = nodeMap.find(nodeId);
    if (it != nodeMap.end()) {
      it->second++;
      sortByWeight();
    }
  }
  void sortByWeight() {
    auto comparator = [](auto a, auto b) { return a < b; };

    std::multimap<int, int, decltype(comparator)> sortedMap(comparator);

    for (std::pair<int, int> pair : nodeMap) {
      auto the_pair = std::make_pair(pair.second, pair.first);
      sortedMap.insert(the_pair);
    }
    nodeMap.clear();
    for (auto pair : sortedMap) {
      nodeMap.insert({pair.second, pair.first});
    }
  }
  std::map<int, int> nodeMap;

private:
};

bool result::gggp(Hypergraph *graph, std::vector<double> &spaceLimit) {
  std::random_device rd;
  std::mt19937 gen(rd());
  NodeWeightStorage the_nodes;
  int hnodeSize = graph->getAllNodes().size() , num = 5;
  int node_num = graph->getAllNodes().size()/2;

  while (num-- > 0) {
    std::vector<bool> nodesPicked(graph->getAllNodes().size(), false);

    double p0size = 0, p1size = getp1size();
    int top = gen() % hnodeSize;

    while (!graph->getNodeExistOf(top)) {
      top++;
      if (top == hnodeSize)
        top = 0;
    }

    while (node_num > 0) {

      if (the_nodes.nodeMap.empty()) {
        int count = 0;
        int top = gen() % hnodeSize;
        for (; count < hnodeSize; count++) {
          if (!nodesPicked[top] && graph->getNodeExistOf(top))
            break;
          top = (top + 1) % hnodeSize;
        }
        if (count == hnodeSize)
          break;
      }
      nodesPicked[top] = true;
      // BFS
      std::vector<int> &edges = graph->getEdgesOf(top);
      for (auto it = edges.begin(); it != edges.end(); it++) {
        std::vector<int> &nodes = graph->getNodesOf(*it);
        int c = graph->getNodeNumOf(*it);
        for (auto itt = nodes.begin(); itt != nodes.begin() + c; itt++) {
          if (!nodesPicked[*itt] && getPartitionOf(*itt) == 1) {
            the_nodes.addNode(*itt);
          }
        }
      }
      top = the_nodes.popMaxWeightNode();
      nodesPicked[top] = true;
      node_num--;

      double weight = graph->getNodeWeightOf(top);
      if (!(p0size + weight > spaceLimit[0])) {
        p0size += weight;
        p1size -= weight;
        setPartitionOf(top, 0);
      }
    }
    setp0size(p0size);
    setp1size(p1size);

    if (p1size <= spaceLimit[1])
      return true;

    this->~result();
    new (this) result(graph);
  }

  return false;
}