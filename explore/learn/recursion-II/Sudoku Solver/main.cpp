#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    size = board.size();
    
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (board[i][j] != '.') {
          row_num[i].insert(board[i][j]);
          col_num[j].insert(board[i][j]);
          seg_num[get_segment(i, j)].insert(board[i][j]);
        }
        else {
          ++dot_count;
        }
      }
    }
    
    backtrack(0, 0, board);
  }

private:
  void backtrack(int row, int col, vector<vector<char>>& board) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
      if (board[row][col] != '.') {
        backtrack(get_next_row(row, col), get_next_col(row, col), board);
      }
      else {
        for (char num = '1'; num <= '9'; ++num) {
          if (is_valid(row, col, num, board)) {
            place_num(row, col, num, board);
            backtrack(get_next_row(row, col), get_next_col(row, col), board);
            remove_num(row, col, num, board);
          }
        }
      }
    }
  }
  
  int get_segment(int i, int j) const {
    return 3 * (i / 3) + (j / 3);
  }

  int get_next_row(int i, int j) const {
    if (j == size - 1) {
      return i + 1;
    }
    return i;
  }

  int get_next_col(int i, int j) const {
    if (j == size - 1) {
      return 0;
    }
    return j + 1;
  }
  
  bool is_valid(int i, int j, char num, vector<vector<char>>& board) {
    return !row_num[i].count(num) && !col_num[j].count(num) && !seg_num[get_segment(i, j)].count(num);
  }
  
  void place_num(int i, int j, char num, vector<vector<char>>& board) {
    row_num[i].insert(num);
    col_num[j].insert(num);
    seg_num[get_segment(i, j)].insert(num);
    board[i][j] = num;
    --dot_count;
  }
  
  void remove_num(int i, int j, char num, vector<vector<char>>& board) {
    if (!is_ready()) {
      row_num[i].erase(num);
      col_num[j].erase(num);
      seg_num[get_segment(i, j)].erase(num);
      board[i][j] = '.';
      ++dot_count;
    }
  }

  bool is_ready() const {
    return dot_count == 0;
  }

private:
  unordered_map<int, unordered_set<char>> row_num;
  unordered_map<int, unordered_set<char>> col_num;
  unordered_map<int, unordered_set<char>> seg_num;

  int size = 0;
  int dot_count = 0;
};

int main() {
  vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  
  Solution solution;
  solution.solveSudoku(board);
  for (const auto& row : board) {
    for (char num : row) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
