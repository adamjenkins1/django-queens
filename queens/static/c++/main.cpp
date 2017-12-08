//main.cpp
//Author: Alexander Corley
//11-01-2017
#include "hill.h"
#include "board.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "[AI] usage: solver <method> <size> <filename>" << std::endl;
    return 1;
  }
  std::string method = argv[1];
  if (method != "Hill") {
    std::cerr << "[AI] error: invalid method type" << std::endl;
    return 3;
  }
  int size = atoi(argv[2]);
  if (size == 0) {
    std::cerr << "[AI] error: size must be an integer" << std::endl;
    return 2;
  }
  std::string filename = argv[3];
  std::ifstream in(filename);
  Board board(size);
  in >> board;
  if (method == "Hill") {
    Hill hill(board);
    std::cout << hill.solve() << std::endl;
    std::cout << hill;
  }
}
