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
  int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int prev_min_mult = nums[0];
    int prev_max_mult = nums[0];
    
    for (int i = 1; i < (int)nums.size(); ++i) {
      int cur_max_mult = max({ prev_min_mult * nums[i], prev_max_mult * nums[i], nums[i] });
      int cur_min_mult = min({ prev_min_mult * nums[i], prev_max_mult * nums[i], nums[i] });
      result = max(result, cur_max_mult);
      prev_max_mult = cur_max_mult;
      prev_min_mult = cur_min_mult;
    }

    return result;
  }
};

int main() {
  return 0;
}
