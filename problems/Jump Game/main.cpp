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
  bool canJump(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < (int)nums.size() - 1; ++i) {
      if (i <= j) {
        j = max(j, i + nums[i]);
      }
      else {
        return false;
      }
    }

    return j >= (int)nums.size() - 1;
  }
};

int main() {
  return 0;
}
