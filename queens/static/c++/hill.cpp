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

unsigned int Hill::h() {

  return 1;
}
