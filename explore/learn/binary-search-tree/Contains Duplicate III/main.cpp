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
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> window;
    
    for (int i = 0; i < int(nums.size()); ++i) {
      if (i > k) {
        window.erase(nums[i - k - 1]);
      }
      
      auto iter = window.lower_bound((long long)nums[i] - t);
      if (iter != window.end() && *iter <= (long long)nums[i] + t) {
        return true;
      }

      window.insert(nums[i]);
    }

    return false;
  }
};

int main() {
  return 0;
}
