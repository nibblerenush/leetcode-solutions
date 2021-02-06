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
  int findTargetSumWays(vector<int>& nums, int S) {
    target = S;
    return dfs(nums, 0, 0);
  }

private:
  int dfs(const vector<int>& nums, int idx, int cur_sum) {
    // size_t to int
    const int size = nums.size();
    
    if (idx >= size) {
      return cur_sum == target ? 1 : 0;
    }
    
    return
      dfs(nums, idx + 1, cur_sum - nums[idx]) +
      dfs(nums, idx + 1, cur_sum + nums[idx]);
  }

private:
  int target = 0;
};

int main() {
  return 0;
}
