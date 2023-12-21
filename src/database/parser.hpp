#pragma once

#include <map>
#include <set>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>
class parser {
public:
  parser() {}

  void read(const std::string &filename);
  void update();
  void write();
  std::vector<std::vector<int>> edges;
  std::set<int> nodes;
  std::map<int, int> mapping;
  std::map<int, int> reserve_mapping;

private:
};
