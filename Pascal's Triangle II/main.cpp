#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> row1(rowIndex + 1, 0);
    std::vector<int> row2(rowIndex + 1, 0);
    bool use_row1 = true;
    
    int prev_size = 0;
    auto fill_row = [&prev_size](std::vector<int>& row1, const std::vector<int>& row2) {
      row1[0] = 1;
      for (int j = 1, i = 1; j <= prev_size; ++j, ++i) {
        if (j == prev_size) {
          row1[i] = 1;
        }
        else {
          row1[i] = row2[i - 1] + row2[i];
        }
      }
    };
    
    for (int row_count = 0; row_count < rowIndex + 1; ++row_count) {
      if (use_row1) {
        use_row1 = false;
        fill_row(row1, row2);
      }
      else {
        use_row1 = true;
        fill_row(row2, row1);
      }
      ++prev_size;
    }
    
    return use_row1 ? row2 : row1;
  }
};

int main() {
  int rowIndex = 0;
  std::cin >> rowIndex;

  Solution solution;
  for (auto num : solution.getRow(rowIndex)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
