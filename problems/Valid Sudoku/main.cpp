#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    const int size = board.size();
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
  return 0;
}
