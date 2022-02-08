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
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.back();
    }
    
    return max(inner_rob(nums, 0, nums.size() - 1), inner_rob(nums, 1, nums.size()));
  }

private:
  int inner_rob(const vector<int>& nums, int left, int right) {
    vector<int> dp(right - left + 1, 0);
    dp[0] = 0;
    dp[1] = nums[left];
    
    for (int i = left + 1, j = 2; i < right; ++i, ++j) {
      dp[j] = max(dp[j - 1], dp[j - 2] + nums[i]);
    }
    
    return dp.back();
  }
};

int main() {
  return 0;
}
