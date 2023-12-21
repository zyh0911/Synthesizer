#pragma once

#include "Hypergraph.hpp"
#include "result.hpp"

#include <cfloat>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Config {
public:
  int numNodeLeft = 20; // number of node left in the last layer of coarsening
  int numInstances =
      20; // number of initial partition done in "initial partition" phase
  double dropRate = 0.3; // drop partition this rate worse than the best
                         // partition in each uncoarsening layer
  int maxCoarsenIter =
      30; // maximum number of coarening layer (stop coarsening even if the
          // number of node left is larger than "numNodeLeft")
  int maxRefineIter =
      30; // maximum number of coarening layer in refinement (stop coarsening
          // even if the number of node left is larger than "numNodeLeft")
  std::string coarsenScheme =
      "MHEC"; // coarsening scheme when coarsening (HEC/MHEC)
  std::string coarsenScheme_r =
      "MHEC"; // coarsening scheme when doing refinement (HEC/MHEC)
  std::string initialParScheme = "FM";
  std::string uncoarsenScheme = "FM";
  std::string uncoarsenScheme_r = "FM";
};

struct partition_info {
  Hypergraph *graph;
  result *inst;
  std::vector<double> spaceLimit;
  std::string scheme;

  partition_info(Hypergraph *graph, result *inst,
                 std::vector<double> spaceLimit, std::string scheme)
      : graph(graph), inst(inst), spaceLimit(spaceLimit), scheme(scheme) {}
};
