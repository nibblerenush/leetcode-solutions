
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int heightChecker(std::vector<int>& heights) {
    auto copy = heights;
    std::sort(heights.begin(), heights.end());

    int result = 0;
    int heights_size = heights.size();
    for (int i = 0; i < heights_size; ++i) {
      if (heights[i] != copy[i]) {
        ++result;
      }
    }

    return result;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> heights(n);
  for (int& height : heights) {
    std::cin >> height;
  }

  Solution solution;
  std::cout << solution.heightChecker(heights) << std::endl;
  return 0;
}
