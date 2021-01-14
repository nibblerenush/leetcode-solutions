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
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    m_target = target;
    for (int i = 0; i < (int)candidates.size(); ++i) {
      backtrack(candidates, i, 0, {});
    }
    return m_result;
  }

private:
  void backtrack(const vector<int>& candidates, int index, int sum, vector<int> combination) {
    while (sum + candidates[index] <= m_target) {
      sum += candidates[index];
      combination.push_back(candidates[index]);
      
      if (sum == m_target) {
        m_result.push_back(move(combination));
      }
      else {
        for (int j = index + 1; j < (int)candidates.size(); ++j) {
          backtrack(candidates, j, sum, combination);
        }
      }
    }
  }

private:
  int m_target = 0;
  vector<vector<int>> m_result;
};

int main() {
  return 0;
}
