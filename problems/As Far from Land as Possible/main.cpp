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
  int maxDistance(vector<vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());

    queue<pair<int, int>> cellQueue, newQueue;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          cellQueue.push({ i + 1, j });
          cellQueue.push({ i - 1, j });
          cellQueue.push({ i, j + 1 });
          cellQueue.push({ i, j - 1 });
        }
      }
    }

    int steps = 0;
    while (!cellQueue.empty()) {
      ++steps;
      while (!cellQueue.empty()) {
        int i = cellQueue.front().first;
        int j = cellQueue.front().second;
        cellQueue.pop();

        if (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
          grid[i][j] = 1;
          newQueue.push({ i + 1, j });
          newQueue.push({ i - 1, j });
          newQueue.push({ i, j + 1 });
          newQueue.push({ i, j - 1 });
        }
      }
      cellQueue = move(newQueue);
    }

    return steps == 0 || steps == 1 ? -1 : steps - 1;
  }
};

int main() {
  return 0;
}
