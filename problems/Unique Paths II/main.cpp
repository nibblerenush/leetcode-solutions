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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    
    // Array "dp" contain number of ways to cell [i, j]
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

    // Fill first row
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[0][j] == 0) {
        dp[0][j] = dp[0][j - 1];
      }
      else {
        dp[0][j] = 0;
      }
    }

    // Fil first column
    for (int i = 1; i < m; ++i) {
      if (obstacleGrid[i][0] == 0) {
        dp[i][0] = dp[i - 1][0];
      }
      else {
        dp[i][0] = 0;
      }
    }
    
    // Main part
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
        else {
          dp[i][j] = 0;
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  return 0;
}
