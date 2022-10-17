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
  int largest1BorderedSquare(vector<vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int maxSide = 0;

    vector<vector<int>> hor(m, vector<int>(n, 0));
    vector<vector<int>> ver(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
          ver[i][j] = i == 0 ? 1 : ver[i - 1][j] + 1;
        }
      }
    }

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int smallSide = min(hor[i][j], ver[i][j]);
        while (smallSide > maxSide) {
          if (hor[i - smallSide + 1][j] >= smallSide && ver[i][j - smallSide + 1] >= smallSide) {
            maxSide = smallSide;
          }
          --smallSide;
        }
      }
    }

    return maxSide * maxSide;
  }
};

int main() {
  return 0;
}
