#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    unordered_map<int, unordered_set<int>> hashmap;
    
    for (int i = 0; i < size; ++i) {
      hashmap[nums[i]].insert(i);
    }

    for (int i = 0; i < size; ++i) {
      int temp = target - nums[i];
      hashmap[nums[i]].erase(i);
      if (!hashmap[temp].empty()) {
        return { i, *hashmap[temp].begin() };
      }
      hashmap[nums[i]].insert(i);
    }

    return {};
  }
};

int main() {
  int target, n;
  cin >> target >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  for (const auto& index : solution.twoSum(nums, target)) {
    cout << index << ' ';
  }
  cout << endl;
  return 0;
}
