#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  int islandPerimeter(vector<vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    int perimeter = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          perimeter += checkAdj(i - 1, j, grid);
          perimeter += checkAdj(i + 1, j, grid);
          perimeter += checkAdj(i, j - 1, grid);
          perimeter += checkAdj(i, j + 1, grid);
        }
      }
    }

    return perimeter;
  }

private:
  int checkAdj(int i, int j, const vector<vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    
    if (i >= 0 && i < m && j >= 0 && j < n) {
      return grid[i][j] == 0 ? 1 : 0;
    }
    return 1;
  }
};

int main() {
  return 0;
}
