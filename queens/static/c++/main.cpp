#include "backtrack.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
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
  if (method != "Hill" && method != "Recursive") {
    cerr << "[AI] error: invalid method type" << endl;
    return 3;
  }
  unsigned int size = atoi(argv[2]);
  if (size == 0) {
    cerr << "[AI] error: size must be an integer" << endl;
    return 2;
  }
  if(method == "Recursive") {
    Backtrack backtrack(size);
    cout << backtrack.solve() << endl;
    backtrack.print();
  }
}
