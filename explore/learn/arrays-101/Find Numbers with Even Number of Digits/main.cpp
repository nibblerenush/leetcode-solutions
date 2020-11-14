#include <iostream>
#include <vector>

class Solution {
public:
  int numberOfDigits(int num) {
    int result = 0;
    while (num != 0) {
      ++result;
      num /= 10;
    }
    return result ? result : 1;
  }

  int findNumbers(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
      if (numberOfDigits(num) % 2 == 0) {
        ++result;
      }
    }
    return result;
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
  std::cout << solution.findNumbers(nums) << std::endl;
  return 0;
}
