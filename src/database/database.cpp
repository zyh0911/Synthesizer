#include "database.hpp"

#include <algorithm>
#include <float.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>

void database::print_node_info(int id)
{
  std::cout << node_num << std::endl;
  std::cout << nodes.at(id).name << std::endl;

  if (nodes.at(id).leftson != -1)
  {
    node_num++;
    std::cout << "Left son:";
    print_node_info(nodes.at(id).leftson);
  }
  if (nodes.at(id).rightson != -1)
  {
    node_num++;
    std::cout << "Right son:";
    print_node_info(nodes.at(id).rightson);
  }
}
void database::output_nodes()
{
  std::cout << nodes.size() << std::endl;
  for (auto &node : nodes)
  {
    std::cout << node.name << " " << node.leftson << " " << node.rightson << " " << node.type << std::endl;
  }
  for (auto mp : name_map)
  {
    std::cout << mp.first << " " << mp.second << std::endl;
  }
}

void database::read(std::string filename)
{

  std::ifstream inputFile(filename);

  if (!inputFile.is_open())
  {
    std::cerr << "Error opening the file." << std::endl;
    return;
  }
  std::string line;
  while (std::getline(inputFile, line))
  {
    for (char token : line)
    {
      if (token != ' ')
      {
        tokens.push_back(std::string(1, token));
      }
    }
  }

  inputFile.close();
}

void database::output()
{
  for (auto token : tokens)
  {
    std::cout << token << std::endl;
  }
  print_node_info(top_node);
}

void database::parser_parent()
{
  auto it = tokens.begin();
  while (it != tokens.end())
  {
    if (*it == "(")
    {
      std::list<std::string> this_tokens;
      auto start = it++;

      while (it != tokens.end() && *it != ")")
      {
        this_tokens.push_back(*it);
        it = tokens.erase(it);
      }

      if (it != tokens.end())
      {
        it = tokens.erase(it);
        int id = parser_not(this_tokens);
        *start = nodes.at(id).name;
      }
    }
    else
    {
      ++it;
    }
  }
}

int database::parser_not(std::list<std::string> &tks)
{
  auto it = tks.begin();
  while (it != tks.end())
  {
    if (*it == "!" || *it == "~")
    {
      auto start = it++;
      nodes.emplace_back();
      nodes.back().name = aid_name.front();
      *start = aid_name.front();
      aid_name.pop_front();
      name_map.emplace(nodes.back().name, nodes.size() - 1);
      top_node = nodes.size() - 1;
      nodes.back().type = 0;
      if (name_map.find(*it) == name_map.end())
      {

        nodes.back().rightson = nodes.size();
        nodes.emplace_back();
        nodes.back().type = 3;
        nodes.back().name = *it;
        name_map.emplace(*it, nodes.size() - 1);
      }
      else
      {
        nodes.back().rightson = name_map.at(*it);
      }
      it = tks.erase(it);
    }
    else
    {
      ++it;
    }
  }
  // for(auto t:tks){
  //   std::cout<<t<<std::endl;
  // }
  return parser_ANDOR(tks);
}

int database::parser_ANDOR(std::list<std::string> &tks)
{
  std::string last_token;
  bool isop = false;
  for (auto token : tks)
  {
    if (token == "&")
    {
      top_node = nodes.size();
      nodes.emplace_back();
      nodes.back().name = aid_name.front();
      aid_name.pop_front();
      name_map.emplace(nodes.back().name, nodes.size() - 1);
      nodes.back().leftson = name_map.at(last_token);
      nodes.back().type = 1;
      isop = true;
    }
    else if (token == "|")
    {
      // std::cout << token << std::endl;
      top_node = nodes.size();
      nodes.emplace_back();
      nodes.back().name = aid_name.front();
      aid_name.pop_front();
      name_map.emplace(nodes.back().name, nodes.size() - 1);
      nodes.back().leftson = name_map.at(last_token);
      nodes.back().type = 2;
      isop = true;
    }
    else
    {
      // std::cout << token << std::endl;
      if (isop)
      {
        if (name_map.find(token) == name_map.end())
        {
          // std::cout<<token<<std::endl;
          nodes.back().rightson = nodes.size();
          last_token = nodes.back().name;
          nodes.emplace_back();
          nodes.back().type = 3;
          nodes.back().name = token;
          name_map.emplace(token, nodes.size() - 1);
        }
        else
        {
          nodes.back().rightson = name_map.at(token);
          last_token = nodes.back().name;
        }

        isop = false;
      }
      else
      {
        if (name_map.find(token) == name_map.end())
        {
          // std::cout<<token<<std::endl;
          nodes.emplace_back();
          nodes.back().type = 3;
          nodes.back().name = token;
          name_map.emplace(token, nodes.size() - 1);
        }
        last_token = token;
      }
    }
  }
  return top_node;
}

void database::erase()
{
  auto it = tokens.begin();
  while (it != tokens.end())
  {
    if (*it == "|")
    {
      auto start = it++;

      if (it != tokens.end() && *it == "|")
      {
        it = tokens.erase(it);
      }
    }
    else
    {
      ++it;
    }
  }
}

void database::parser()
{
  erase();
  parser_parent();
  parser_not(tokens);
  parser_ANDOR(tokens);
  convert_aig();
  // output_nodes();
  // output();
}

int database::getnodenum(int id)
{
  if (nodes.at(id).type == 3)
  {
    return input_map.at(nodes.at(id).name);
  }
  else if (nodes.at(id).type == 0)
  {
    return 1 + getnodenum(nodes.at(id).rightson);
  }
  else if (nodes.at(id).type == 1)
  {
    int left = getnodenum(nodes.at(id).leftson);
    int right = getnodenum(nodes.at(id).rightson);
    if (gate_map.find(std::make_pair(left, right)) != gate_map.end())
    {
      return gate_map.at(std::make_pair(left, right));
    }
    gate_map.emplace(std::make_pair(left, right), gate_num);
    aig_gates.emplace_back();
    aig_gates.back().emplace_back(gate_num);
    aig_gates.back().emplace_back(left);
    aig_gates.back().emplace_back(right);
    gate_num += 2;
    return gate_num - 2;
  }
  else if (nodes.at(id).type == 2)
  {
    int left;
    if (getnodenum(nodes.at(id).leftson) % 2 == 1)
    {
      left = getnodenum(nodes.at(id).leftson) - 1;
    }
    else
    {
      left = getnodenum(nodes.at(id).leftson) + 1;
    }
    int right = getnodenum(nodes.at(id).rightson) + 1;
    if (gate_map.find(std::make_pair(left, right)) != gate_map.end())
    {
      return gate_map.at(std::make_pair(left, right));
    }
    gate_map.emplace(std::make_pair(left, right), gate_num);
    aig_gates.emplace_back();
    aig_gates.back().emplace_back(gate_num);
    aig_gates.back().emplace_back(left);
    aig_gates.back().emplace_back(right);
    gate_num += 2;
    return gate_num - 1;
  }
}

void database::convert_aig()
{
  for (int i = 0; i < nodes.size(); i++)
  {
    int left_son = nodes.at(i).leftson;
    int right_son = nodes.at(i).rightson;
    for (int j = i + 1; j < nodes.size(); j++)
    {
      if (nodes.at(j).check(left_son, right_son))
      {
        nodes.at(j).name = nodes.at(i).name;
      }
    }
  }

  for (int i = 0; i < nodes.size(); i++)
  {
    if (std::islower(nodes.at(i).name[0]))
    {
      if (input_map.find(nodes.at(i).name) == input_map.end())
      {
        input_map.emplace(nodes.at(i).name, input_num);
        input_num += 2;
      }
    }
  }

  gate_num = input_num + 2;
  output_num = getnodenum(top_node);
  std::cout << "aag " << input_map.size() + aig_gates.size() << " " << input_map.size() << " 0 1 " << aig_gates.size() << std::endl;

  for (int i = 0; i < input_map.size(); i++)
  {
    std::cout << 2 * i + 2 << std::endl;
  }

  if (nodes.at(top_node).type == 2)
  {
    aig_gates.back().at(0) = input_num;
    std::cout << input_num+1 << std::endl;
  }
  else
  {
    aig_gates.back().at(0) = input_num;
    std::cout << input_num  << std::endl;
  }

  for (const auto &aiggate : aig_gates)
  {
    std::cout << aiggate.at(0) << " " << aiggate.at(1) << " " << aiggate.at(2) << std::endl;
  }
}