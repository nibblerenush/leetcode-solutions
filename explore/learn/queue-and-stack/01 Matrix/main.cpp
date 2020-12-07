#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& matrix) {
    int row_size = matrix.size();
    int col_size = matrix[0].size();

    std::vector<std::vector<int>> result(row_size, std::vector<int>(col_size, std::numeric_limits<int>::max()));
    std::queue<std::pair<int, int>> work_queue;
    for (int i = 0; i < row_size; ++i) {
      for (int j = 0; j < col_size; ++j) {
        if (matrix[i][j] == 0) {
          result[i][j] = 0;
          work_queue.push({i, j});
        }
      }
    }

    while (!work_queue.empty()) {
      auto cur_i = work_queue.front().first;
      auto cur_j = work_queue.front().second;
      work_queue.pop();

      checkCell(cur_i, cur_j, cur_i - 1, cur_j, row_size, col_size, result, work_queue);
      checkCell(cur_i, cur_j, cur_i + 1, cur_j, row_size, col_size, result, work_queue);
      checkCell(cur_i, cur_j, cur_i, cur_j - 1, row_size, col_size, result, work_queue);
      checkCell(cur_i, cur_j, cur_i, cur_j + 1, row_size, col_size, result, work_queue);
    }

    return result;
  }

private:
  void checkCell(
    int cur_i,
    int cur_j,
    int i,
    int j,
    int row_size,
    int col_size,
    std::vector<std::vector<int>>& result,
    std::queue<std::pair<int, int>>& work_queue)
  {
    if (i >= 0 && i < row_size && j >= 0 && j < col_size) {
      if (result[cur_i][cur_j] + 1 < result[i][j]) {
        result[i][j] = result[cur_i][cur_j] + 1;
        work_queue.push({i ,j});
      }
    }
  }
};

int main() {
  int m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
  for (auto& row : matrix) {
    for (auto& cell : row) {
      std::cin >> cell;
    }
  }

  Solution solution;
  auto result = solution.updateMatrix(matrix);
  for (const auto& row : result) {
    for (const auto& cell : row) {
      std::cout << cell << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
