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
  int minDistance(string word1, string word2) {
    int str_a_len = word1.length();
    int str_b_len = word2.length();
    
    vector<vector<int>> dp(str_a_len + 1);
    for (auto& row : dp) {
      row.resize(str_b_len + 1);
    }

    for (int j = 0; j <= str_b_len; ++j) {
      dp[0][j] = j;
    }

    for (int i = 0; i <= str_a_len; ++i) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= str_a_len; ++i) {
      for (int j = 1; j <= str_b_len; ++j) {
        int diff = diff_func(word1[i - 1], word2[j - 1]);
        dp[i][j] = min({ dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + diff });
      }
    }

    return dp[str_a_len][str_b_len];
  }

private:
  int diff_func(char c1, char c2) {
    return c1 == c2 ? 0 : 1;
  }
};

int main() {
  return 0;
}
