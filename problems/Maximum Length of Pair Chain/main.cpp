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
  int findLongestChain(vector<vector<int>>& pairs) {
    const int n = pairs.size();
    
    sort(pairs.begin(), pairs.end());
    
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (pairs[i][0] > pairs[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return dp.back();
  }
};

int main() {
  return 0;
}
