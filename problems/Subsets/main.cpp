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
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subset;
    vector<vector<int>> result;
    backtrack(nums, 0, subset, result);
    return result;
  }

private:
  void backtrack(const vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& subsets) {
    subsets.push_back(subset);
    
    for (int i = index; i < (int)nums.size(); ++i) {
      subset.push_back(nums[i]);
      backtrack(nums, i + 1, subset, subsets);
      subset.pop_back();
    }
  }
};

int main() {
  return 0;
}
