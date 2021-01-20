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
  bool exist(vector<vector<char>>& board, string word) {
    bool result = false;
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = result || backtrack(board, i, j, word, 0);
      }
    }
    
    return result;
  }

private:
  bool backtrack(vector<vector<char>>& board, int i, int j, const string& word, int index) {
    if (index >= (int)word.length()) {
      return true;
    }
    
    if (!check_symbol(board, i, j, word[index])) {
      return false;
    }

    char temp = board[i][j];
    board[i][j] = '.';
    bool result =
      backtrack(board, i + 1, j, word, index + 1) ||
      backtrack(board, i - 1, j, word, index + 1) ||
      backtrack(board, i, j + 1, word, index + 1) ||
      backtrack(board, i, j - 1, word, index + 1);
    board[i][j] = temp;
    return result;
  }
  
  bool check_symbol(const vector<vector<char>>& board, int i, int j, char c) {
    int m = board.size();
    int n = board[0].size();
    return i >= 0 && i < m && j >= 0 && j < n && board[i][j] == c;
  }
};

int main() {
  return 0;
}
