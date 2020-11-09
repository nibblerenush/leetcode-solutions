#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
  bool find132pattern(std::vector<int>& nums) {
    std::vector<int> min_array(nums.size());
    min_array[0] = nums[0];
    for (std::size_t i = 1; i < min_array.size(); ++i) {
      min_array[i] = std::min(min_array[i - 1], nums[i]);
    }
    
    std::set<int> work_set;
    for (int i = static_cast<int>(nums.size()) - 1; i > 0; --i) {
      auto iter = work_set.lower_bound(nums[i]);
      if (iter != work_set.begin() && *std::prev(iter) < nums[i]) {
        int left = min_array[i - 1];
        int right = *std::prev(iter);
        if (left < right) {
          return true;
        }
      }
      work_set.insert(nums[i]);
    }
    return false;
  }
};

int main() {
  std::vector<int> nums = { 1, 2, 3, 4 };

  Solution solution;
  std::cout << std::boolalpha << solution.find132pattern(nums) << std::endl;
  return 0;
}
