#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  int thirdMax(std::vector<int>& nums) {
    long int max1 = std::numeric_limits<long int>::min();
    long int max2 = max1, max3 = max1;

    for (int num : nums) {
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      else if (num != max1 && num > max2) {
        max3 = max2;
        max2 = num;
      }
      else if (num != max1 && num != max2 && num > max3) {
        max3 = num;
      } 
    }

    if (max3 != std::numeric_limits<long int>::min()) {
      return max3;
    }
    else {
      return max1;
    }
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
  std::cout << solution.thirdMax(nums) << std::endl;
  return 0;
}
