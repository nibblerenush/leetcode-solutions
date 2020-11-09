#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result;
    int prev_size = 0;
    
    for (int i = 0; i < numRows; ++i) {
      result.push_back(std::vector<int>{1});
      
      for (int j = 1; j <= prev_size; ++j) {
        if (j == prev_size) {
          result[i].push_back(1);
        }
        else {
          result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
      prev_size++;
    }

    return result;
  }
};

int main() {
  int numRows = 0;
  std::cin >> numRows;
  
  Solution solution;
  auto result = solution.generate(numRows);
  for (const auto& row : result) {
    for (auto num : row) {
      std::cout << num << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
