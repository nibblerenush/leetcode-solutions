#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int dominantIndex(std::vector<int>& nums) {
    auto max_value_iter = std::max_element(nums.begin(), nums.end());
    for (int num : nums) {
      if (num != *max_value_iter && 2 * num > *max_value_iter) {
        return -1;
      }
    }
    
    return std::distance(nums.begin(), max_value_iter);
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (int& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  std::cout << solution.dominantIndex(nums) << std::endl;
  return 0;
}
