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
  int minimumDeleteSum(string s1, string s2) {
    const int l1 = (int)s1.length();
    const int l2 = (int)s2.length();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i < l1 + 1; ++i) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    
    for (int j = 1; j < l2 + 1; ++j) {
      dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    
    for (int i = 1; i < l1 + 1; ++i) {
      for (int j = 1; j < l2 + 1; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else {
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
      }
    }
    
    return dp[l1][l2];
  }
};

int main() {
  return 0;
}
