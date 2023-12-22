#include "database/database.hpp"

#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::string filename1 = "../../test/case6.txt";
    database db = database();
    db.read(filename1);
    db.parser();
  } else if (argc > 2) {
  }
  return 0;
}
