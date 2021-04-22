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
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          dfs_mark(i, j, 'Y', board);
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs_mark(i, j, 'X', board);
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'Y') {
          board[i][j] = 'O';
        }
      }
    }
  }

private:
  void dfs_mark(int i, int j, char mark, vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    
    if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
      board[i][j] = mark;

      dfs_mark(i + 1, j, mark, board);
      dfs_mark(i - 1, j, mark, board);
      dfs_mark(i, j + 1, mark, board);
      dfs_mark(i, j - 1, mark, board);
    }
  }
};

int main() {
  return 0;
}
