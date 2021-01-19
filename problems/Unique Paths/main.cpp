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
  int uniquePaths(int m, int n) {
    vector<vector<int>> dynamic(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i) {
      dynamic[i][0] = 1;
    }
    
    for (int j = 0; j < n; ++j) {
      dynamic[0][j] = 1;
    }
    
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dynamic[i][j] = dynamic[i - 1][j] + dynamic[i][j - 1];
      }
    }
    
    return dynamic[m - 1][n - 1];
  }
};

int main() {
  return 0;
}
