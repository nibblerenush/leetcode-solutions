#include <iostream>
#include <vector>

class Solution {
public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int result = 0;
    const int nums_size = nums.size();
    
    int count = 0;
    for (int i = 0; i < nums_size; ++i) {
      if (nums[i] == 1) {
        count++;
      }
      else {
        result = std::max(result, count);
        count = 0;
      }
    }
    
    return std::max(result, count);
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
    if (num < 0 || num > 1) {
      std::cout << "Invalid num" << std::endl;
      return 1;
    }
  }

  Solution solution;
  std::cout << solution.findMaxConsecutiveOnes(nums) << std::endl;
  return 0;
}
