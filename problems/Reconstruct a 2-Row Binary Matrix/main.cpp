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
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    const int n = colsum.size();
    int curUpper = 0;
    int curLower = 0;

    vector<vector<int>> matrix(2, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
      if (colsum[i] == 2) {
        matrix[0][i] = 1;
        ++curUpper;
        
        matrix[1][i] = 1;
        ++curLower;
        
        if (curUpper > upper || curLower > lower) {
          return {};
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (colsum[i] == 1) {
        if (curUpper < upper) {
          matrix[0][i] = 1;
          ++curUpper;
        }
        else if (curLower < lower) {
          matrix[1][i] = 1;
          ++curLower;
        }
        else {
          return {};
        }
      }
    }

    if (curUpper == upper && curLower == lower) {
      return matrix;
    }
    return {};
  }
};

int main() {
  return 0;
}
