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
  void setZeroes(vector<vector<int>>& matrix) {
    bool is_first_row_zero = false;
    bool is_first_col_zero = false;
    
    for (int i = 0; i < (int)matrix.size(); ++i) {
      for (int j = 0; j < (int)matrix[0].size(); ++j) {
        if (i == 0 && matrix[i][j] == 0) {
          is_first_row_zero = true;
        }
        
        if (j == 0 && matrix[i][j] == 0) {
          is_first_col_zero = true;
        }
        
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    
    for (int i = 1; i < (int)matrix.size(); ++i) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < (int)matrix[0].size(); ++j) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int j = 1; j < (int)matrix[0].size(); ++j) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < (int)matrix.size(); ++i) {
          matrix[i][j] = 0;
        }
      }
    }

    if (is_first_row_zero) {
      for (int j = 0; j < (int)matrix[0].size(); ++j) {
        matrix[0][j] = 0;
      }
    }

    if (is_first_col_zero) {
      for (int i = 0; i < (int)matrix.size(); ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main() {
  return 0;
}
