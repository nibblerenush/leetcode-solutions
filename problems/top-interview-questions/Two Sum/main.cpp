#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (std::size_t i = 0; i < nums.size(); ++i) {
      int second_num = target - nums[i];
      auto iter = std::find(nums.begin() + i + 1, nums.end(), second_num);
      if (iter != nums.end()) {
        return { static_cast<int>(i), static_cast<int>(std::distance(nums.begin(), iter)) };
      }
    }

    return {};
  }
};

int main() {
  std::vector<int> nums = { 2,7,11,15 };
  int target = 9;

  Solution solution;
  for (int num : solution.twoSum(nums, target)) {
    std::cout << num << ' ';
  }
  return 0;
}
