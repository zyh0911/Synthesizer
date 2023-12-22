#include "database.hpp"

#include <algorithm>
#include <float.h>

#include <fstream>
#include <iostream>
#include <string>

void database::read(std::string filename) {

  std::ifstream inputFile(filename);

  if (!inputFile.is_open()) {
    std::cerr << "Error opening the file." << std::endl;
    return;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    for (char token : line) {

    }
  }

  inputFile.close(); // 不要忘记关闭文件
}