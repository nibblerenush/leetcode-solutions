#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int size = board.size();
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (board[i][j] != '.') {
          if (!row_num[i].insert(board[i][j]).second ||
              !col_num[j].insert(board[i][j]).second ||
              !seg_num[get_segment(i, j)].insert(board[i][j]).second)
          {
            return false;
          }
        }
      }
    }
    return true;
  }

private:
  int get_segment(int i, int j) const {
    return 3 * (i / 3) + (j / 3);
  }

private:
  unordered_map<int, unordered_set<char>> row_num;
  unordered_map<int, unordered_set<char>> col_num;
  unordered_map<int, unordered_set<char>> seg_num;
};

int main() {
  vector<vector<char>> board = {
    {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
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
  cout << boolalpha << solution.isValidSudoku(board) << endl;
  return 0;
}
