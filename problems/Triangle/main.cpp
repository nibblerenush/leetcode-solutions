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
  int minimumTotal(vector<vector<int>>& triangle) {
    const int m = triangle.size();
    // Array "dp" contains current min sum
    vector<int> dp(m, 0);
    
    // From buttom of triangle
    for (int i = m - 1; i >= 0; --i) {
      const int n = triangle[i].size();
      
      for (int j = 0; j < n; ++j) {
        if (i < m - 1) {
          dp[j] = min(dp[j], dp[j + 1]);
        }
        
        dp[j] += triangle[i][j];
      }
    }
    
    return dp[0];
  }
};

int main() {
  return 0;
}
