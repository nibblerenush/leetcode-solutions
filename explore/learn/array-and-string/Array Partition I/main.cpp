#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int i = 0;
    int j = i + 1;
    int result = 0;

    while (j < static_cast<int>(nums.size())) {
      result += std::min(nums[i], nums[j]);
      i += 2;
      j = i + 1;
    }

    return result;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  if (n % 2 != 0) {
    std::cout << "Invalid n" << std::endl;
    return 1;
  }

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  std::cout << solution.arrayPairSum(nums) << std::endl;
  return 0;
}
