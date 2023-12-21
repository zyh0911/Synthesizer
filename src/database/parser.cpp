#include "parser.hpp"

void parser::read(const std::string &filename) {
  std::ifstream inputf(filename);
  if (!inputf) {
    std::cout << "Can't open file!" << std::endl;
    return;
  }
  std::string line;
  bool begin = false;
  while (getline(inputf, line)) {
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> words;
    while (std::getline(ss, word, ' ')) {
      words.emplace_back(word);
    }

    if (!words.empty()) {
      if (words.at(0) == "0") {
        begin = true;
      }
      if (begin == true) {
        edges.emplace_back();
        for (int i = 1; i < words.size(); i++) {
          edges.back().emplace_back(std::stoi(words.at(i)));
          nodes.insert(std::stoi(words.at(i)));
        }
      }
    }
  }
  update();
}

void parser::write() {
  for (int i = 0; i < edges.size(); i++) {
    std::cout << i;
    for (int j = 0; j < edges.at(i).size(); j++) {
      std::cout << " " << edges.at(i).at(j);
    }
    std::cout << std::endl;
  }
}

void parser::update() {
  int i = 0;
  for (const auto &node : nodes) {
    mapping.emplace(node, i);
    i++;
  }
  for (const auto &pair : mapping) {
    reserve_mapping.emplace(pair.second, pair.first);
    i++;
  }

}