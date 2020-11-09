#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> result;

    int temp = 1;
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
      if (digits[i] + temp == 10) {
        result.push_back(0);
        if (i == 0) {
          result.push_back(1);
        }
      }
      else {
        result.push_back(digits[i] + temp);
        temp = 0;
      }
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  int n;
  std::cin >> n;

  std::vector<int> digits(n);
  for (int& digit : digits) {
    std::cin >> digit;
  }

  Solution solution;
  auto results = solution.plusOne(digits);
  for (int result : results) {
    std::cout << result << ' ';
  }
  std::cout << std::endl;
  return 0;
}
