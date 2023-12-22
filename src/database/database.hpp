#pragma once

//#include "../algorithm/coarsening.hpp"


#include <list>
#include <stack>
#include <string>
#include <vector>

class node{
  public:
    int parent=-1;
    int leftson=-1;
    int rightson=-1;
    int type=-1; // 0: NOT 1: AND 2:OR
};

class database {
private:
  std::vector<node> spaceLimit;

public:
  database() = default;
  void read(std::string filename);
  void write();
  
};

