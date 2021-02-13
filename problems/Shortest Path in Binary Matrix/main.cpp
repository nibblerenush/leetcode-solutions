#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // size_t to int
    const int size = grid.size();

    // prepare
    vector<vector<int>> distances(size, vector<int>(size, -1));
    queue<pair<pair<int, int>, pair<int, int>>> work_queue;
    work_queue.push({ {0, 0}, {-1, -1} });

    while (!work_queue.empty()) {
      int i = work_queue.front().first.first;
      int j = work_queue.front().first.second;

      int parent_i = work_queue.front().second.first;
      int parent_j = work_queue.front().second.second;

      work_queue.pop();

      if (is_correct_cell(grid, i, j, distances)) {
        if (parent_i == -1 && parent_j == -1) {
          distances[i][j] = 1;
        }
        else {
          distances[i][j] = distances[parent_i][parent_j] + 1;
        }

        work_queue.push({ {i - 1, j - 1}, {i, j} });
        work_queue.push({ {i - 1, j}, {i, j} });
        work_queue.push({ {i - 1, j + 1}, {i, j} });
        work_queue.push({ {i, j - 1}, {i, j} });
        work_queue.push({ {i, j + 1}, {i, j} });
        work_queue.push({ {i + 1, j - 1}, {i, j} });
        work_queue.push({ {i + 1, j}, {i, j} });
        work_queue.push({ {i + 1, j + 1}, {i, j} });
      }
    }

    return distances[size - 1][size - 1];
  }

private:
  bool is_correct_cell(const vector<vector<int>>& grid, int i, int j, const vector<vector<int>>& distances) {
    const int size = grid.size();
    return i >= 0 && i < size && j >= 0 && j < size && grid[i][j] == 0 && distances[i][j] == -1;
  }
};

int main() {
  return 0;
}
