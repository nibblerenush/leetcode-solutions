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
  int minimumEffortPath(vector<vector<int>>& heights) {
    int left = 0;
    int right = 1'000'000;
    
    while (left < right) {
      int mid = left + (right - left) / 2;
      
      if (check_threshold(heights, mid)) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
    
    return left;
  }

private:
  bool check_threshold(const vector<vector<int>>& heights, int k) {
    const int m = heights.size();
    const int n = heights[0].size();
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    dfs(heights, heights[0][0], 0, 0, k, visited);
    return visited[m - 1][n - 1];
  }
  
  void dfs(const vector<vector<int>>& heights, int height, int i, int j, int k, vector<vector<bool>>& visited) {
    if (check_cell(heights, height, i, j, k, visited)) {
      visited[i][j] = true;
      
      dfs(heights, heights[i][j], i + 1, j, k, visited);
      dfs(heights, heights[i][j], i - 1, j, k, visited);
      dfs(heights, heights[i][j], i, j + 1, k, visited);
      dfs(heights, heights[i][j], i, j - 1, k, visited);
    }
  }
  
  bool check_cell(const vector<vector<int>>& heights, int height, int i, int j, int k, vector<vector<bool>>& visited) {
    const int m = heights.size();
    const int n = heights[0].size();
    return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j] && abs(heights[i][j] - height) <= k;
  }
};

int main() {
  return 0;
}
