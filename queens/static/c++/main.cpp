#include "hill.h"
#include <iostream>
#include <fstream>
using std::endl;
using std::cerr;
using std::cout;
using std::string;
using std::ifstream;

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "[AI] usage: solver <method> <size> <filename>" << endl;
    return 1;
  }
  string method = argv[1];
  if (method != "Hill") {
    cerr << "[AI] error: invalid method type" << endl;
    return 3;
  }
  int size = atoi(argv[2]);
  if (size == 0) {
    cerr << "[AI] error: size must be an integer" << endl;
    return 2;
  }
  //string filename = argv[3];
  //ifstream in(filename);
  if (method == "Hill") {
    Hill hill(size);
    hill.print();
    //cout << hill.solve() << endl;
    //cout << hill;
  }
}
