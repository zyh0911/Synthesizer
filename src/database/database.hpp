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
  int type = -1; // 0: NOT 1: AND 2:OR 3: INPUT
  bool check(int left_son, int right_son)
  {
    if(left_son==-1 and right_son==-1){
      return false;
    }
    bool result1 = (left_son == leftson) && (right_son == rightson);
    bool result2 = (left_son == rightson) && (right_son == leftson);
    return result1 || result2;
  }
};

class database
{
private:
  std::list<std::string> aid_name{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O"};
  std::list<std::string> tokens;
  std::vector<node> nodes;
  std::map<std::string, int> name_map; // <input name, nodeid>
  int top_node = -1;
  int node_num = 0;
  void parser_parent();
  int parser_not(std::list<std::string> &tks);
  void erase();
  int parser_ANDOR(std::list<std::string> &tks);
  void print_node_info(int id);
  void output_nodes();
  int getnodenum(int id);

public:
  database() = default;
  std::vector<std::vector<int>> aig_gates;
  int input_num = 2;
  int output_num = 2;
  int gate_num=2;
  std::map<std::string, int> input_map;
  std::map<std::pair<int,int>, int> gate_map;
  void read(std::string filename);
  void output();
  void parser();
  void convert_aig();
  // void write();
};
