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
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    
    vector<int> dynamic(nums.size() + 1);
    dynamic[0] = 0;
    dynamic[1] = nums[0];
    
    for (int i = 1; i < (int)nums.size(); ++i) {
      int j = i + 1;
      dynamic[j] = max(dynamic[j - 1], dynamic[j - 2] + nums[i]);
    }

    return dynamic.back();
  }
};

int main() {
  return 0;
}
