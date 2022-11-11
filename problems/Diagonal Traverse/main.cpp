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
  enum class Direct {
    UP,
    DOWN
  };

  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) {
      return result;
    }
    
    int current_row = 0;
    int current_column = 0;
    const int rows_count = matrix.size();
    const int columns_count = matrix[0].size();
    
    Direct direct = Direct::UP;
    result.reserve(rows_count * columns_count);
    
    while (result.size() != rows_count * columns_count) {
      int i = current_row;
      int j = current_column;

      if (direct == Direct::UP) {
        while (i >= 0 && i < rows_count && j >= 0 && j < columns_count) {
          current_row = i;
          current_column = j;
          result.push_back(matrix[i--][j++]);
        }

        if (current_column < columns_count - 1) {
          current_column++;
        }
        else if (current_row < rows_count - 1) {
          current_row++;
        }

        direct = Direct::DOWN;
      }
      else {
        while (i >= 0 && i < rows_count && j >= 0 && j < columns_count) {
          current_row = i;
          current_column = j;
          result.push_back(matrix[i++][j--]);
        }

        if (current_row < rows_count - 1) {
          current_row++;
        }
        else if (current_column < columns_count - 1) {
          current_column++;
        }

        direct = Direct::UP;
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
