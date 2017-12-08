#include "hill.h"
#include <cmath>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using std::srand;
using std::time;
using std::make_pair;
using std::pair;
using std::ostream;
using std::rand;
using std::vector;
using std::find;
using std::cout;
using std::endl;

Hill::Hill(unsigned int size) {
  srand(time(0));
  m_size = size;
  m_board = generate_board();
}

vector<vector<int> > Hill::generate_board() {
  unsigned int i = 0;
  vector<int> choices;
  vector<vector<int> >tmpBoard(8, vector<int>(8, 0));
  for(unsigned int k = 0; k < m_size; k++) {
    choices.push_back(k);
  }

  while(true) {
    int random = rand() % m_size;
    vector<int>::iterator it;
    it = find(choices.begin(), choices.end(), random);
    if(it != choices.end()) {
      choices.erase(it);
      tmpBoard[i][random] = 1;
      i++;
    }
    if(choices.size() == 0)
      break;
  }
  return tmpBoard;
}

void Hill::print() {
  for(unsigned int i = 0; i < m_size; i++) {
    for(unsigned int j = 0; j < m_size; j++) {
      cout << m_board[i][j] << " ";
    }
    cout << endl;
  }
}

/*
   bool Hill::solve() {
   Board best(orig);
   int iters = 0, retries = 0;
   while (fin.H != 0 && retries < MAX_RETRIES) {
   std::pair<int, int> loc = get_random_loc();
   int row = loc.first, col = loc.second;
   std::vector<Board> vals;
   int min = -1, min_val = 0;
   for (int i = 0; i < size; ++i) {
   vals.push_back(fin);
   if (orig.get(row, i) == 0)
   vals[i].swap(row, col, row, i);
   if (vals[i].H < min || min == -1) {
   min = vals[i].H;
   min_val = i;
   }
   }
   fin = vals[min_val];
   if (iters > 1000) {
   fin = Board::generate_rand(orig);
   iters = 0;
   retries++;
   }
   iters++;
   if (fin.H < best.H)
   best = fin;
   }
   if (fin > best)
   fin = best;
   return fin.H == 0;
   }

   pair<int, int> Hill::get_random_loc() {
   return valid_locs[rand()/RAND_MAX*valid_locs.size()];
   }

   ostream& operator<<(ostream& out, const Hill& ob) {
   out << ob.fin << "\n";
   return out;
   }
   */
