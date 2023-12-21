#pragma once

#include "../database/Hypergraph.hpp"
#include "../database/result.hpp"

#include <ctime>
#include <random>
#include <vector>

struct sort_edge_info {
  int idx, nodeNum;
  double weight;

  sort_edge_info(int idx, int nodeNum, double weight)
      : idx(idx), nodeNum(nodeNum), weight(weight){};
};

class EC_Coarsening {
public:
  EC_Coarsening() = default;

  // coarsen nodes in a hypergraph
  // return coarsened hypergraph
  // bool for if the coarsening is "restricted"
  std::vector<std::pair<int, std::vector<int> *>> *
  Coarsening(Hypergraph *, result *, std::vector<double> &spaceLimit, bool);

  // return the id of maximal weight matching node (EC coarsening)
  int getMaxWeightMatch(const int);

  // return vector of the weight for each node
  // node weight: the sum of weights of all the edges connected to a node
  std::vector<double> computeNodeWeights(Hypergraph *);

  // return connected maximum weight node of n1
  // bool for choose node in the same partition
  int chooseMaxWeight(Hypergraph *, result *, std::vector<double> &,
                      std::vector<double> &, std::vector<bool> &, int, bool);

  // set edge weights for lower level graph from upper level graph
  void computeWeights(Hypergraph *, Hypergraph *);
};

class HEC_Coarsening {
public:
  HEC_Coarsening() = default;

  // main function of HEC coarsening
  // MHEC for "modified" HEC
  std::vector<std::pair<int, std::vector<int> *>> *
  Coarsening(Hypergraph *, result *, std::vector<double> &, bool, bool);

  // return sorted edge idx with respect to weight and size
  std::vector<int> sortEdge(Hypergraph *);

  // return true if all node indexes in the first vector is not matched
  // otherwise return false
  bool nodesNotMatched(std::vector<int> &, int, std::vector<bool> &);

  // return true if the whole edge belongs to the same partition
  bool preservePartition(result *, std::vector<int> &, int);
};

class Coarsen {
private:
  EC_Coarsening EC;
  HEC_Coarsening HEC;

public:
  Coarsen() : EC(EC_Coarsening()), HEC(HEC_Coarsening()) { srand(time(NULL)); };

  // coarsen nodes in a hypergraph
  // return coarsened hypergraph
  // bool for if the coarsening is "restricted"
  std::vector<std::pair<int, std::vector<int> *>> *
  Coarsening(Hypergraph *, result *, std::vector<double> &, bool,
             std::string &);
};