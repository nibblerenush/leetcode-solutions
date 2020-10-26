#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  int pivotIndex(std::vector<int>& nums) {
    int all_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;

    for (std::size_t i = 0; i < nums.size(); ++i) {
      int right_sum = all_sum - left_sum - nums[i];
      if (right_sum == left_sum) {
        return i;
      }
      left_sum += nums[i];
    }

    return -1;
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
  std::cout << solution.pivotIndex(nums) << std::endl;
  return 0;
}
