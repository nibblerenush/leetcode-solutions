#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int numbers_size = numbers.size();
    
    for (int i = 0; i < numbers_size - 1; ++i) {
      int second_part = target - numbers[i];
      auto iter = std::lower_bound(numbers.begin() + i + 1, numbers.end(), second_part);
      if (*iter == second_part) {
        return { i + 1, static_cast<int>(std::distance(numbers.begin(), iter) + 1) };
      }
    }

    return {};
  }
};

int main() {
  int target = 0, n = 0;
  std::cin >> target >> n;

  std::vector<int> numbers(n);
  for (auto& number : numbers) {
    std::cin >> number;
  }
  std::sort(numbers.begin(), numbers.end());

  Solution solution;
  auto results = solution.twoSum(numbers, target);
  for (auto result : results) {
    std::cout << result << ' ';
  }
  std::cout << std::endl;
  return 0;
}
