#pragma once

#include <cfloat>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class HyperNode {
private:
  std::vector<int> edges;
  std::vector<int> neighbors;
  double weight = 1.0;

public:
  HyperNode() : edges({}), neighbors({}), weight(0.0){};
  HyperNode(double weight, int part)
      : edges({}), neighbors({}), weight(weight){};

  // add an edge to the hypernode
  void addEdge(int);

  // return all edges of the hypernode
  std::vector<int> &getEdges();

  // return all neighbors of the hypernode
  std::vector<int> &getNeighbors();

  double getNodeWeight();

  void setNodeWeight(double);
};

class HyperEdge {
private:
  double weight;
  int count;
  std::vector<int> nodes;

public:
  HyperEdge(std::vector<int> &nodes, double weight)
      : nodes(nodes), count(nodes.size()), weight(weight){};

  // get all nodes in the hyperedge
  std::vector<int> &getNodes();

  // return weight of the edge
  double getEdgeWeight();

  void relinkNode(int, int);

  void deleteNode(int);

  int getNodeNum();

  void setNodeNum(int);
};

class Hypergraph {
private:
  std::vector<HyperNode *> nodes;
  std::vector<HyperEdge *> edges;
  std::vector<bool> nodeExist, edgeExist;
  int nodeNum;

public:
  Hypergraph() : nodes({}), edges({}){};
  Hypergraph(int nvtxs, int nedges)
      : edges({}), nodeExist(std::vector<bool>(nvtxs, true)),
        edgeExist(std::vector<bool>(nedges, true)), nodeNum(nvtxs) {
    nodes.reserve(nvtxs);
    for (int i = 0; i < nvtxs; i++)
      nodes.push_back(new HyperNode());
  };
  ~Hypergraph() {
    for (int i = 0; i < nodes.size(); i++)
      delete nodes[i];
    for (int i = 0; i < edges.size(); i++)
      delete edges[i];
  }

  // add a new edge and the given node list
  // which are connected to the new edge
  void addNodeList(int edge_id, std::vector<int> &vtxs);

  // add a hypernode to the hypergraph and increase partition size
  void addNode(HyperNode *);

  // return all hyperedges in the current graph
  std::vector<HyperEdge *> &getAllEdges();

  // return all hypernodes in the current graph
  std::vector<HyperNode *> &getAllNodes();

  // return connected edges of the given node index
  std::vector<int> &getEdgesOf(int);

  // return connected nodes of the given edge index
  std::vector<int> &getNodesOf(int);

  // return node number
  int getNodeNum();

  // return edge number
  int getEdgeNum();

  // return node Weight
  double getNodeWeightOf(int);

  // return edge weight of the node
  double getEdgeWeightOf(int);

  // return neighbors of the given node index
  std::vector<int> &getNeighborsOf(int);

  std::pair<int, std::vector<int> *> coarseNodes(std::vector<int> *);

  int getNodeNumOf(int);

  bool getEdgeExistOf(int);

  bool getNodeExistOf(int);

  void deleteNodeOf(int, int);

  void relinkNodeOf(int, int);

  void setEdgeExistOf(int, bool);

  void setNodeExistOf(int, bool);

  void setNodeNumOf(int, int);

  void setNodeNum(int);

  void setNodeWeightOf(int, double);

  // build and merge neighbors of all nodes after coarsening
  void buildNeighbors();

  void revertGraph(std::vector<std::pair<int, std::vector<int> *>> *);

  // check if the size of the given node vector is under space limit
  bool sizeUnderLimit(std::vector<int> &, int, double);

  // display current graph in database format
  void displayGraph();
};
