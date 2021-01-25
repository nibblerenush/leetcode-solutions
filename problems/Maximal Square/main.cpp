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
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int result = 0;
    vector<vector<int>> dynamic(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      dynamic[i][0] = matrix[i][0] == '1' ? 1 : 0;
      result = max(result, dynamic[i][0]);
    }

    for (int j = 0; j < n; ++j) {
      dynamic[0][j] = matrix[0][j] == '1' ? 1 : 0;
      result = max(result, dynamic[0][j]);
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == '0') {
          dynamic[i][j] = 0;
        }
        else {
          dynamic[i][j] = min({ dynamic[i - 1][j], dynamic[i][j - 1], dynamic[i - 1][j - 1] }) + 1;
          result = max(result, dynamic[i][j]);
        }
      }
    }

    return result * result;
  }
};

int main() {
  return 0;
}
