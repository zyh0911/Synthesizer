#include "database/database.hpp"
#include "database/info.hpp"

#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    Config config;
    std::string filename1 = "../../test/100.txt";
    parser the_parser;
    the_parser.read(filename1);
     the_parser.write();
    std::cout << "---------" << std::endl;
    database db = database();
    std::cout << "---------" << std::endl;

    db.configureGraph(the_parser);
    std::cout << "---------" << std::endl;

    db.coarsen(config.numNodeLeft, false, config.coarsenScheme,
               config.maxCoarsenIter);
    std::cout << "---------" << std::endl;

    db.initialPartition(config.numInstances, config.initialParScheme);
    std::cout << "---------" << std::endl;

    db.uncoarsen(config.dropRate, config.uncoarsenScheme);
    std::cout << "---------" << std::endl;

    db.refine(config.numNodeLeft, config.dropRate, config.coarsenScheme_r,
              config.uncoarsenScheme_r, config.maxRefineIter);
    std::cout << "---------" << std::endl;

    db.outputGraph(the_parser);
    std::cout << "---------" << std::endl;
  } else if (argc > 2) {
  }
  return 0;
}
