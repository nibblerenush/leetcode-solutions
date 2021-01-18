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
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result);
    return result;
  }

private:
  void backtrack(const vector<int>& nums, vector<vector<int>>& permutations) {
    if (permutation.size() == nums.size()) {
      permutations.push_back(permutation);
      return;
    }
    
    for (int num : nums) {
      if (!used_nums.count(num)) {
        place_num(num);
        backtrack(nums, permutations);
        remove_num(num);
      }
    }
  }

private:
  void place_num(int num) {
    permutation.push_back(num);
    used_nums.insert(num);
  }

  void remove_num(int num) {
    permutation.pop_back();
    used_nums.erase(num);
  }

private:
  vector<int> permutation;
  unordered_set<int> used_nums;
};

int main() {
  return 0;
}
