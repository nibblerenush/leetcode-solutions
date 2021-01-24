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
  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int result = 0;
    
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          queue<pair<int, int>> work_queue;
          work_queue.push({ i, j });
          visited[i][j] = true;
          
          while (!work_queue.empty()) {
            pair<int, int> indexes = work_queue.front();
            work_queue.pop();
            
            check_and_add(grid, indexes.first + 1, indexes.second, visited, work_queue);
            check_and_add(grid, indexes.first - 1, indexes.second, visited, work_queue);
            check_and_add(grid, indexes.first, indexes.second + 1, visited, work_queue);
            check_and_add(grid, indexes.first, indexes.second - 1, visited, work_queue);
          }
          
          result += 1;
        }
      }
    }
    
    return result;
  }

private:
  void check_and_add(const vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited, queue<pair<int, int>>& work_queue) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    if (i >= 0 && i < rows && j >= 0 && j < cols && !visited[i][j] && grid[i][j] == '1') {
      work_queue.push({ i, j });
      visited[i][j] = true;
    }
  }
};

int main() {
  return 0;
}
