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
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    int maxArea = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (matrix[i - 1][j - 1] == '0') {
          dp[i][j] = 0;
        }
        else {
          dp[i][j] = dp[i][j - 1] + 1;
          
          int row = i;
          int height = 0;
          int width = numeric_limits<int>::max();
          
          while (row >= 0 && dp[row][j] != 0) {
            height += 1;
            width = min(width, dp[row][j]);
            maxArea = max(maxArea, height * width);
            row -= 1;
          }
        }
      }
    }
    
    return maxArea;
  }
};

int main() {
  return 0;
}
