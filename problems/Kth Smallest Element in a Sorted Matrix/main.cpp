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

class Solution
{
public:
  int kthSmallest(vector<vector<int>>& matrix, int k)
  {
    int n = matrix.size();
    int revert_k = n * n - k + 1;
    int result = 0;
    
    for (int i = 0; i < revert_k; ++i)
    {
      int max_val = numeric_limits<int>::min();
      int max_idx = 0;
      
      for (int j = 0; j < n; ++j)
      {
        if (!matrix[j].empty() && matrix[j].back() > max_val)
        {
          max_val = matrix[j].back();
          max_idx = j;
        }
      }
      
      matrix[max_idx].pop_back();
      result = max_val;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
