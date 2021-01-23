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
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    unordered_map<int, vector<int>> id_diag;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        id_diag[i - j].push_back(mat[i][j]);
      }
    }
    
    for (auto& item : id_diag) {
      sort(item.second.begin(), item.second.end(), greater<int>());
    }
    
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result[i][j] = id_diag[i - j].back();
        id_diag[i - j].pop_back();
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
