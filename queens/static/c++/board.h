#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
using std::vector;
using std::ostream;
using std::istream;

#define USE_ALTERNATE_H true

//this class just holds boards for the genetic algorithm to play with

class Board {
  public:
    Board(const vector<vector<int> >&);
    Board(int);
    int get_size() const {return size; }
    void set(int, int, int);
    int get(int, int) const;
    void swap(int, int, int, int);
    vector<int> get_col(int) const;
    vector<int> get_row(int) const;
    void set_col(int, const vector<int>&);
    void set_row(int, const vector<int>&);
    void trade_cols(vector<int>, Board&);
    void trade_rows(vector<int>, Board&);
    friend bool operator<(const Board&, const Board&);
    friend bool operator>(const Board&, const Board&);
    friend ostream& operator<<(ostream& out, const Board& ob);
    friend istream& operator>>(istream& in, Board& ob);
    void print_board(ostream& out) const;
    static Board generate_rand(Board& board);
    int H;
    //whether it should use a alternate fitness function
  private:
    vector<vector<int> > board;
    unsigned int size;
    void h();
};

#endif //BOARD_H
