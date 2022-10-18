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
  int longestCommonSubsequence(string text1, string text2) {
    const int n1 = static_cast<int>(text1.length());
    const int n2 = static_cast<int>(text2.length());

    vector<vector<int>> dp(n1, vector<int>(n2, 0));
    
    for (int i = 0; i < n1; ++i) {
      if (text1[i] == text2[0]) {
        dp[i][0] = 1;
      }
      else if (i != 0) {
        dp[i][0] = dp[i - 1][0];
      }
    }

    for (int j = 0; j < n2; ++j) {
      if (text2[j] == text1[0]) {
        dp[0][j] = 1;
      }
      else if (j != 0) {
        dp[0][j] = dp[0][j - 1];
      }
    }

    for (int i = 1; i < n1; ++i) {
      for (int j = 1; j < n2; ++j) {
        if (text1[i] == text2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[n1 - 1][n2 - 1];
  }
};

int main() {
  return 0;
}
