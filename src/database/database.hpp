#pragma once

#include "../algorithm/coarsening.hpp"
#include "../algorithm/refinement.hpp"
#include "Hypergraph.hpp"
#include "info.hpp"
#include "parser.hpp"

#include <list>
#include <stack>
#include <string>
#include <vector>

class database {
private:
  Hypergraph *graph;
  std::list<result *> Instances;
  std::vector<double> spaceLimit;
  std::vector<std::vector<std::pair<int, std::vector<int> *>> *> coarsenInfo;

public:
  database() = default;

  // int uncoarCnt = 0;
  // multiset<pair<double, pair<int, int>>> sizeOrder;

  // build graph by the given box
  void configureGraph(parser &the_parser);

  // output partitioned graph to the given box
  void outputGraph(parser &the_parser);

  // database coarsening
  // bool for if the coarsening is "restricted"
  void coarsen(int, bool, std::string, int);

  // database initial partitioning
  // int for the number of Instances desired
  // void initialPartition(int, Hypergraph&);
  void initialPartition(int, std::string);

  // database uncoarsening
  // double stands for 'dropRate'
  void uncoarsen(double, std::string);

  // new_partition uncoarsening
  void newUncoarsen();

  // database refine
  void refine(int, double, std::string, std::string, int);

  // return the size of instances[]
  int getInstanceSize();

  // drop instances which are 'dropRate' worse than the best cut (0.1 stands for
  // 10 percent)
  void dropWorstCut(double);

  void chooseBestInstance();

  // return sorted node idx in non-decreasing node size order
  std::vector<int> sortNode(Hypergraph *);

  void preIPAdjustment();
};
