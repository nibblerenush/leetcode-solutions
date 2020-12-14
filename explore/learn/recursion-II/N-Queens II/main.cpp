#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int totalNQueens(int n) {
    is_attacking.assign(n, vector<int>(n, 0));
    size = n;
    return backtrack(0, 0);
  }

private:
  int backtrack(int row, int count) {
    for (int col = 0; col < size; ++col) {
      if (!is_attacking[row][col]) {
        place_queen(row, col);
        if (row + 1 == size) {
          ++count;
        }
        else {
          count = backtrack(row + 1, count);
        }
        remove_queen(row, col);
      }
    }
    return count;
  }

private:
  void place_queen(int row, int col) {
    move_queen(row, col, 1);
  }
  
  void remove_queen(int row, int col) {
    move_queen(row, col, -1);
  }

  void move_queen(int row, int col, int value) {
    is_attacking[row][col] += value;
    
    for (int j = 0; j < size; ++j) {
      if (j != col) {
        is_attacking[row][j] += value;
      }
    }
    
    for (int i = 0; i < size; ++i) {
      if (i != row) {
        is_attacking[i][col] += value;
      }
    }

    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && i < size && j >= 0 && j < size) {
      is_attacking[i--][j--] += value;
    }

    i = row + 1;
    j = col + 1;
    while (i >= 0 && i < size && j >= 0 && j < size) {
      is_attacking[i++][j++] += value;
    }

    i = row - 1;
    j = col + 1;
    while (i >= 0 && i < size && j >= 0 && j < size) {
      is_attacking[i--][j++] += value;
    }

    i = row + 1;
    j = col - 1;
    while (i >= 0 && i < size && j >= 0 && j < size) {
      is_attacking[i++][j--] += value;
    }
  }

private:
  vector<vector<int>> is_attacking;
  int size = 0;
};

int main() {
  int n = 0;
  std::cin >> n;

  Solution solution;
  std::cout << solution.totalNQueens(n) << std::endl;
  return 0;
}
