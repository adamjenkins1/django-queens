#include "backtrack.h"
#include <iostream>
#include <vector>
using std::vector;
using std::endl;
using std::cout;

Backtrack::Backtrack(int size) {
  m_size = size;
  vector<vector<int> > board(m_size, vector<int>(m_size, 0));
  m_board = board;

}

bool Backtrack::validSpace(int row, int col) {
  int i = 0, j = 0;

  for (i = 0; i < col; i++) {
    if (m_board[row][i] != 0) {
      return false; 
    }
  }

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (m_board[i][j] != 0) {
      return false; 
    }
  }

  for (i = row, j = col; j >= 0 && i < m_size; i++, j--) {
    if (m_board[i][j] != 0) {
      return false;
    }
  }

  return true;
}

bool Backtrack::solveRecursively(int col) {
  if (col >= m_size) {
    return true;
  }

  for (int i = 0; i < m_size; i++)
  {
    if (validSpace(i, col))
    {
      m_board[i][col] = 1;

      if (solveRecursively(col + 1)) {
        return true;
      }

      m_board[i][col] = 0;
    }
  }

  return false;
}

bool Backtrack::solve() {
  if(solveRecursively(0) == false) {
    return false;
  }

  return true;
}

void Backtrack::print() {
  for(int i = 0; i < m_size; i++) {
    for(int j = 0; j < m_size; j++) {
      cout << m_board[i][j] << " ";
    }
    #ifdef DEBUG
    cout << endl;
    #endif
  }
}
