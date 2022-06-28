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
  int orangesRotting(vector<vector<int>>& grid) {
    vector<pair<int, int>> rottenOranges;
    FindInitialRottenOranges(grid, rottenOranges);
    
    int minutes = 0;
    while (!rottenOranges.empty())
    {
      vector<pair<int, int>> newRottenOranges;
      for (const auto& item : rottenOranges)
      {
        int i = item.first;
        int j = item.second;
        CheckCell(grid, i + 1, j, newRottenOranges);
        CheckCell(grid, i - 1, j, newRottenOranges);
        CheckCell(grid, i, j + 1, newRottenOranges);
        CheckCell(grid, i, j - 1, newRottenOranges);
      }

      if (!newRottenOranges.empty()) ++minutes;
      rottenOranges = move(newRottenOranges);
    }

    return IsHasFreshOrange(grid) ? -1 : minutes;
  }

private:
  void CheckCell(
    vector<vector<int>>& grid,
    int i,
    int j,
    vector<pair<int, int>>& newRottenOranges)
  {
    const int m = grid.size();
    const int n = grid[0].size();

    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == freshOrangeCell)
    {
      newRottenOranges.push_back({ i, j });
      grid[i][j] = rottenOrangeCell;
    }
  }

  void FindInitialRottenOranges(
    const vector<vector<int>>& grid,
    vector<pair<int, int>>& rottenOranges)
  {
    const int m = grid.size();
    const int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == rottenOrangeCell)
        {
          rottenOranges.push_back({ i, j });
        }
      }
    }
  }

  bool IsHasFreshOrange(const vector<vector<int>>& grid)
  {
    const int m = grid.size();
    const int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == freshOrangeCell)
        {
          return true;
        }
      }
    }
    return false;
  }

private:
  static const int emptyCell = 0;
  static const int freshOrangeCell = 1;
  static const int rottenOrangeCell = 2;
};

int main() {
  return 0;
}
