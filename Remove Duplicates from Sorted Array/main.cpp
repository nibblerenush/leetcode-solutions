#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    const int nums_size = nums.size();

    for (int j = 0; j < nums_size; ++j) {
      if (j == 0 || nums[j] > nums[j - 1]) {
        nums[i++] = nums[j];
      }
    }

    return i;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }
  std::sort(nums.begin(), nums.end());

  Solution solution;
  int len = solution.removeDuplicates(nums);
  for (int i = 0; i < len; ++i) {
    std::cout << nums[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
