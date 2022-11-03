#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  int getMaximumGold(vector<vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        backtrack(i, j, grid, 0);
      }
    }

    return result;
  }

private:
  void backtrack(int i, int j, vector<vector<int>>& grid, int curGold) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    
    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != 0) {
      curGold += grid[i][j];
      int gridVal = grid[i][j];
      grid[i][j] = 0;
      backtrack(i + 1, j, grid, curGold);
      backtrack(i - 1, j, grid, curGold);
      backtrack(i, j + 1, grid, curGold);
      backtrack(i, j - 1, grid, curGold);
      grid[i][j] = gridVal;
      curGold -= grid[i][j];
    }
    else {
      result = max(result, curGold);
    }
  }

private:
  int result = 0;
};

int main() {
  return 0;
}
