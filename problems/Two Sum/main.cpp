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
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> num_indexes;
    for (int i = 0; i < (int)nums.size(); ++i) {
      num_indexes[nums[i]].push_back(i);
    }
    
    int num1 = 0;
    int num2 = 0;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < (int)nums.size() - 1; ++i) {
      int num = target - nums[i];
      if (binary_search(nums.begin() + i + 1, nums.end(), num)) {
        num1 = nums[i];
        num2 = *lower_bound(nums.begin() + i + 1, nums.end(), num);
        break;
      }
    }
    
    vector<int> result;
    if (num1 == num2) {
      result.push_back(num_indexes[num1][0]);
      result.push_back(num_indexes[num1][1]);
    }
    else {
      result.push_back(num_indexes[num1][0]);
      result.push_back(num_indexes[num2][0]);
    }
    
    return result;
  }
};

int main() {
  return 0;
}
