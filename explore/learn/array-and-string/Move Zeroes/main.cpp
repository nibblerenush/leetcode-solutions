#include <iostream>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int i = 0;
    const int nums_size = nums.size();

    for (int j = 0; j < nums_size; ++j) {
      if (nums[j] != 0) {
        nums[i++] = nums[j];
      }
    }

    std::fill(nums.begin() + i, nums.end(), 0);
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  solution.moveZeroes(nums);
  for (auto num : nums) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
