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
    int right = 999'999;
    
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      pair<bool, bool> check = check_threshold(heights, mid);
      
      if (check.first && !check.second) {
        return mid;
      }
      else if (check.first && check.second) {
        right = mid;
      }
      else {
        left = mid;
      }
    }
    
    pair<bool, bool> check = check_threshold(heights, left);
    if (check.first && !check.second) {
      return left;
    }
    
    check = check_threshold(heights, right);
    if (check.first && !check.second) {
      return right;
    }
    
    return -1;
  }

private:
  pair<bool, bool> check_threshold(const vector<vector<int>>& heights, int k) {
    const int m = heights.size();
    const int n = heights[0].size();
    
    pair<bool, bool> result;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    dfs(heights, heights[0][0], 0, 0, k, visited);
    result.first = visited[m - 1][n - 1];
    
    visited.assign(m, vector<bool>(n, false));
    dfs(heights, heights[0][0], 0, 0, k - 1, visited);
    result.second = visited[m - 1][n - 1];
    
    return result;
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
