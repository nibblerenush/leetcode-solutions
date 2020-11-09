#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    const int nums_size = nums.size();
    k %= nums_size;

    int i = 0;
    int j = nums_size - 1;
    while (i < j) {
      std::swap(nums[i++], nums[j--]);
    }

    i = 0;
    j = k - 1;
    while (i < j) {
      std::swap(nums[i++], nums[j--]);
    }

    i = k;
    j = nums_size - 1;
    while (i < j) {
      std::swap(nums[i++], nums[j--]);
    }
  }
};

int main() {
  int k = 0, n = 0;
  std::cin >> k >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  solution.rotate(nums, k);
  for (auto num : nums) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
