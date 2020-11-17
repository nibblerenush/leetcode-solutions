
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    int i = 0;
    int nums_size = nums.size();
    std::vector<int> result;

    while (i < nums_size) {
      if (nums[i] == i + 1 || nums[i] == 0) {
        ++i;
      }
      else {
        int swap_idx = nums[i] - 1;
        std::swap(nums[i], nums[swap_idx]);
        if (nums[i] == nums[swap_idx]) {
          nums[i] = 0;
        }
      }
    }

    for (i = 0; i < nums_size; ++i) {
      if (nums[i] == 0) {
        result.push_back(i + 1);
      }
    }

    return result;
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
  for (int num : solution.findDisappearedNumbers(nums)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
