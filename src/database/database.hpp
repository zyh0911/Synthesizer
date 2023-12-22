#pragma once

//#include "../algorithm/coarsening.hpp"


#include <list>
#include <stack>
#include <string>
#include <vector>

class database {
private:
  std::vector<double> spaceLimit;
  std::vector<std::vector<std::pair<int, std::vector<int> *>> *> coarsenInfo;

public:
  database() = default;

  
};
