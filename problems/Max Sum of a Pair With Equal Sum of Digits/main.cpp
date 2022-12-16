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
  int maximumSum(vector<int>& nums) {
    const int numsSize = static_cast<int>(nums.size());
    unordered_map<int, multiset<int>> digitSumNums;
    
    for (int num : nums) {
      int digitSum = getDigitSum(num);
      digitSumNums[digitSum].insert(num);
    }
    
    int result = -1;
    for (auto item : digitSumNums) {
      const multiset<int>& nums = item.second;
      if (nums.size() > 1) {
        result = max(result, *prev(nums.end()) + *prev(prev(nums.end())));
      }
    }
    
    return result;
  }

private:
  int getDigitSum(int num) {
    int result = 0;
    while (num) {
      result += num % 10;
      num /= 10;
    }
    return result;
  }
};

int main() {
  return 0;
}
