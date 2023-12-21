#pragma once
#include "Hypergraph.hpp"

#include <algorithm>
#include <cfloat>
#include <float.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <unordered_set>
#include <utility>
#include <vector>

class result {
private:
  std::vector<int> part;
  double p0size, p1size, partScore;

public:
  result(Hypergraph *g)
      : part(std::vector<int>(g->getAllNodes().size(), 1)), p0size(0),
        partScore(DBL_MAX) {
    p1size = 0;
    for (int i = 0; i < g->getAllNodes().size(); i++)
      if (g->getNodeExistOf(i))
        p1size += g->getNodeWeightOf(i);
  }

  double getp0size();

  double getp1size();

  double getPartitionScore();

  int getPartitionOf(int);

  void setp0size(double);

  void setp1size(double);

  void setPartitionScore(double);

  void setPartitionOf(int, int);

  void computePartitionScore(Hypergraph *);

  void mapPartition(std::vector<std::pair<int, std::vector<int> *>> *);

  bool ggp(Hypergraph *, std::vector<double> &);

  bool gggp(Hypergraph *, std::vector<double> &);
};