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
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int result = nums[0];
    
    for (int num : nums) {
      sum = max(sum + num, num);
      result = max(result, sum);
    }

    return result;
  }
};

int main() {
  return 0;
}
