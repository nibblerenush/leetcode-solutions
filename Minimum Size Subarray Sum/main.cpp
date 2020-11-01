#include <iostream>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int s, std::vector<int>& nums) {
    int i = 0;
    int j = 0;
    const int nums_size = nums.size();
    int result = nums_size + 1;
    
    int cur_sum = 0;
    while (i < nums_size) {
      if (cur_sum < s) {
        cur_sum += nums[i++];
      }
      else {
        while (cur_sum >= s) {
          result = std::min(result, i - j);
          cur_sum -= nums[j++];
        }
      }
    }
    
    while (cur_sum >= s) {
      result = std::min(result, i - j);
      cur_sum -= nums[j++];
    }

    return result == nums_size + 1 ? 0 : result;
  }
};

int main() {
  int s = 0, n = 0;
  std::cin >> s >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }

  Solution solution;
  std::cout << solution.minSubArrayLen(s, nums) << std::endl;
  return 0;
}
