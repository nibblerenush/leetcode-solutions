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
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = i + 1;
    int result = 0;

    while (j < static_cast<int>(nums.size())) {
      result += min(nums[i], nums[j]);
      i += 2;
      j = i + 1;
    }

    return result;
  }
};

int main() {
  return 0;
}
