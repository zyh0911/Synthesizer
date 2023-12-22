#pragma once

#include <list>
#include <stack>
#include <string>
#include <vector>
#include <map>

class node
{
public:
  std::string name;
  int leftson = -1;
  int rightson = -1;
  int type = -1; // 0: NOT 1: AND 2:OR 3: INPUT 4:PARENT

};

class database
{
private:
  std::list<std::string> aid_name{"Z","Y","H","A","B","C","F","K","X"};
  std::list<std::string> tokens;
  std::vector<node> nodes;
  std::map<std::string, int> name_map; // <input name, nodeid>
  int top_node=-1;
  int node_num=0;
  void parser_parent();
  int parser_not(std::list<std::string>& tks);
  void erase();
  int parser_ANDOR(std::list<std::string>& tks);
  void print_node_info( int id);
public:
  database() = default;
  void read(std::string filename);
  void output();
  void parser();
  // void write();
};
