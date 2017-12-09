#ifndef BACKTRACK_H
#define BACKTRACK_H
#include <vector>
using std::vector;

class Backtrack {
  public:
    Backtrack(int);
    bool validSpace(int, int);
    void print();
    bool solve();
    bool solveRecursively(int);
  private:
    int m_size;
    vector<vector<int> > m_board;
};

#endif
