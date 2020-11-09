#include <iostream>
#include <vector>

class Solution {
public:
  enum class Direct {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    if (matrix.empty()) {
      return result;
    }

    int low_row = 0;
    int low_col = 0;
    int high_row = matrix.size() - 1;
    int high_col = matrix[0].size() - 1;

    Direct direct = Direct::RIGHT;
    result.reserve(matrix.size() * matrix[0].size());

    while (result.size() != matrix.size() * matrix[0].size()) {
      if (direct == Direct::RIGHT) {
        int i = low_row;
        int j = low_col;
        while (j <= high_col) {
          result.push_back(matrix[i][j++]);
        }
        low_row++;
        direct = Direct::DOWN;
      }
      else if (direct == Direct::DOWN) {
        int i = low_row;
        int j = high_col;
        while (i <= high_row) {
          result.push_back(matrix[i++][j]);
        }
        high_col--;
        direct = Direct::LEFT;
      }
      else if (direct == Direct::LEFT) {
        int i = high_row;
        int j = high_col;
        while (j >= low_col) {
          result.push_back(matrix[i][j--]);
        }
        high_row--;
        direct = Direct::UP;
      }
      else if (direct == Direct::UP) {
        int i = high_row;
        int j = low_col;
        while (i >= low_row) {
          result.push_back(matrix[i--][j]);
        }
        low_col++;
        direct = Direct::RIGHT;
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
  auto result = solution.spiralOrder(matrix);
  for (int num : result) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
