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
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> rawResult;
    vector<vector<int>> allResult;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, 0, target, 0, rawResult, allResult);
    return allResult;
  }

private:
  void backtrack(
    const vector<int>& candidates,
    size_t beginIndex,
    int target,
    int sumToTarget,
    vector<int>& rawResult,
    vector<vector<int>>& allResult)
  {
    if (sumToTarget == target)
    {
      allResult.push_back(rawResult);
      return;
    }

    if (sumToTarget > target)
    {
      return;
    }

    for (size_t i = beginIndex; i < candidates.size(); ++i)
    {
      if (i == beginIndex || candidates[i] != candidates[i - 1])
      {
        rawResult.push_back(candidates[i]);
        sumToTarget += candidates[i];
        backtrack(candidates, i + 1, target, sumToTarget, rawResult, allResult);
        sumToTarget -= candidates[i];
        rawResult.pop_back();
      }
    }
  }
};

int main() {
  return 0;
}
