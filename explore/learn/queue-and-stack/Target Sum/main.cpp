#include <iostream>
#include <vector>

class Solution {
public:
  int helper(const std::vector<int>& nums, int idx, int cur_sum, int S) {
    if (idx >= static_cast<int>(nums.size())) {
      return cur_sum == S ? 1 : 0;
    }
    
    return helper(nums, idx + 1, cur_sum - nums[idx], S) + helper(nums, idx + 1, cur_sum + nums[idx], S);
  }
  
  int findTargetSumWays(std::vector<int>& nums, int S) {
    return helper(nums, 0, 0, S);
  }
};

int main() {
  int S = 0, n = 0;
  std::cin >> S >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  std::cout << solution.findTargetSumWays(nums, S) << std::endl;
  return 0;
}
