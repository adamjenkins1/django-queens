#ifndef HILL_H
#define HILL_H
#include <utility>
#include <vector>
#include <iostream>
using std::ostream;
using std::vector;
using std::pair;

class Hill {
  public:
    static const int MAX_RETRIES = 100;
    Hill(unsigned int);
    //friend ostream& operator<<(ostream&, const Hill&);
    bool solve() {return true;}
    void print();
    vector<vector<int> > generate_board();
  private:
    unsigned int m_size;
    vector<vector<int> > m_board;

    pair<int, int> get_random_loc();
    vector<pair<int, int>> valid_locs;
};

#endif //HILL_H
