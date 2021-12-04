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

class Solution
{
public:
  void gameOfLife(vector<vector<int>>& board)
  {
    const int m = board.size();
    const int n = board[0].size();

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        int live_cell_count = 0;
        int dead_cell_count = 0;
        count_cells(board, i + 1, j, live_cell_count, dead_cell_count);
        count_cells(board, i - 1, j, live_cell_count, dead_cell_count);
        count_cells(board, i, j + 1, live_cell_count, dead_cell_count);
        count_cells(board, i, j - 1, live_cell_count, dead_cell_count);
        count_cells(board, i + 1, j + 1, live_cell_count, dead_cell_count);
        count_cells(board, i + 1, j - 1, live_cell_count, dead_cell_count);
        count_cells(board, i - 1, j + 1, live_cell_count, dead_cell_count);
        count_cells(board, i - 1, j - 1, live_cell_count, dead_cell_count);

        if (board[i][j] == 1)
        {
          if (live_cell_count < 2)
          {
            // State changed from 1 to 0
            board[i][j] = -1;
          }
          else if (live_cell_count == 2 || live_cell_count == 3)
          {
            // State saved
            board[i][j] = 1;
          }
          else if (live_cell_count > 3)
          {
            // State changed from 1 to 0
            board[i][j] = -1;
          }
        }
        else if (board[i][j] == 0)
        {
          if (live_cell_count == 3)
          {
            // State changed from 0 to 1
            board[i][j] = -2;
          }
        }
      }
    }

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (board[i][j] == -1)
        {
          board[i][j] = 0;
        }
        else if (board[i][j] == -2)
        {
          board[i][j] = 1;
        }
      }
    }
  }

private:
  void count_cells(
    const vector<vector<int>>& board,
    int i,
    int j,
    int& live_cell_count,
    int& dead_cell_count) const
  {
    const int m = board.size();
    const int n = board[0].size();

    if (i >= 0 && i < m && j >= 0 && j < n)
    {
      if (board[i][j] == 0 || board[i][j] == -2)
      {
        dead_cell_count++;
      }
      else if (board[i][j] == 1 || board[i][j] == -1)
      {
        live_cell_count++;
      }
    }
  }
};

int main() {
  return 0;
}
