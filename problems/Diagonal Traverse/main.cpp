#include <iostream>
#include <vector>

class Solution {
public:
  enum class Direct {
    UP,
    DOWN
  };

  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    if (matrix.empty()) {
      return result;
    }
    
    int current_row = 0;
    int current_column = 0;
    const int rows_count = matrix.size();
    const int columns_count = matrix[0].size();
    
    Direct direct = Direct::UP;
    result.reserve(rows_count * columns_count);
    
    while (result.size() != rows_count * columns_count) {
      int i = current_row;
      int j = current_column;

      if (direct == Direct::UP) {
        while (i >= 0 && i < rows_count && j >= 0 && j < columns_count) {
          current_row = i;
          current_column = j;
          result.push_back(matrix[i--][j++]);
        }

        if (current_column < columns_count - 1) {
          current_column++;
        }
        else if (current_row < rows_count - 1) {
          current_row++;
        }

        direct = Direct::DOWN;
      }
      else {
        while (i >= 0 && i < rows_count && j >= 0 && j < columns_count) {
          current_row = i;
          current_column = j;
          result.push_back(matrix[i++][j--]);
        }

        if (current_row < rows_count - 1) {
          current_row++;
        }
        else if (current_column < columns_count - 1) {
          current_column++;
        }

        direct = Direct::UP;
      }
    }
    
    return result;
  }
};

int main() {
  int m = 0;
  int n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
  for (std::vector<int>& row : matrix) {
    for (int& column : row) {
      std::cin >> column;
    }
  }

  Solution solution;
  auto result = solution.findDiagonalOrder(matrix);
  for (int num : result) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
