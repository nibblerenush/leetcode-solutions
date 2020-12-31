#include <algorithm>
#include <cmath>
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
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int nums_size = nums.size();
    unordered_map<int, vector<int>> num_indexes;

    for (int i = 0; i < nums_size; ++i) {
      num_indexes[nums[i]].push_back(i);
    }

    for (const auto& item : num_indexes) {
      const auto& indexes = item.second;
      int size = indexes.size();
      
      for (int i = 0; i < size - 1; ++i) {
        if (abs(indexes[i] - indexes[i + 1]) <= k) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << boolalpha << solution.containsNearbyDuplicate(nums, k) << endl;
  return 0;
}
