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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    
    int i = 0;
    int j = n - 1;
    
    while (i < m && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      }
      else if (target > matrix[i][j]) {
        i += 1;
      }
      else {
        j -= 1;
      }
    }
    
    return false;
  }
};

int main() {
  return 0;
}
