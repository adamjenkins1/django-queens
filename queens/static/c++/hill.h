#ifndef HILL_H
#define HILL_H
#include "board.h"
#include <utility>
using std::ostream;
using std::vector;
using std::pair;

class Hill {
  public:
    static const int MAX_RETRIES = 100;
    Hill(const Board&);
    friend ostream& operator<<(ostream&, const Hill&);
    bool solve();
  private:
    Board orig, fin;
    int size;
    pair<int, int> get_random_loc();
    vector<pair<int, int>> valid_locs;
};

#endif //HILL_H
