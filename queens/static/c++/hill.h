#ifndef HILL_H
#define HILL_H
#include <vector>
using std::vector;

class Hill {
  public:
    static const int MAX_RETRIES = 100;
    Hill(unsigned int);
    bool solve() {return true;} // fix later
    void print();
    vector<vector<int> > generate_board();
    unsigned int h();
  private:
    unsigned int m_size;
    vector<vector<int> > m_board;
};

#endif
