#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    int j = 0;
    int nums_size = nums.size();

    for (int i = 0; i < nums_size; ++i) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }

    return j;
  }
};

int main() {
  int val = 0, n = 0;
  std::cin >> val >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  int len = solution.removeElement(nums, val);
  for (int i = 0; i < len; ++i) {
    std::cout << nums[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
