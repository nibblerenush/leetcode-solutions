#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int result = 0;
    
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          std::queue<std::pair<int, int>> work_queue;
          work_queue.push({ i, j });
          visited[i][j] = true;
          
          while (!work_queue.empty()) {
            auto indexes = work_queue.front();
            work_queue.pop();

            checkAndAdd(indexes.first + 1, indexes.second, grid, visited, work_queue);
            checkAndAdd(indexes.first - 1, indexes.second, grid, visited, work_queue);
            checkAndAdd(indexes.first, indexes.second + 1, grid, visited, work_queue);
            checkAndAdd(indexes.first, indexes.second - 1, grid, visited, work_queue);
          }
          
          ++result;
        }
      }
    }

    return result;
  }

private:
  void checkAndAdd(
    int cur_i,
    int cur_j,
    const std::vector<std::vector<char>>& grid,
    std::vector<std::vector<bool>>& visited,
    std::queue<std::pair<int, int>>& work_queue)
  {
    int rows = grid.size();
    int cols = grid[0].size();
    
    if (cur_i < rows && cur_i >= 0 && cur_j < cols && cur_j >= 0 && !visited[cur_i][cur_j] && grid[cur_i][cur_j] == '1') {
      work_queue.push({ cur_i, cur_j });
      visited[cur_i][cur_j] = true;
    }
  }
};

int main() {
  int m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<char>> grid(m, std::vector<char>(n, 0));
  for (auto& row : grid) {
    for (auto& cell : row) {
      std::cin >> cell;
    }
  }

  Solution solution;
  std::cout << solution.numIslands(grid) << std::endl;
  return 0;
}
