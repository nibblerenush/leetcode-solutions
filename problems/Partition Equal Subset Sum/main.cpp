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
  bool canPartition(vector<int>& nums) {
    // size_t to int
    const int size = nums.size();
    
    // calc all_sum
    int all_sum = accumulate(nums.begin(), nums.end(), 0);
    if (all_sum % 2 != 0) {
      return false;
    }
    all_sum /= 2;
    
    // init dynamic
    vector<vector<int>> dynamic(all_sum + 1, vector<int>(size + 1, 0));
    
    for (int j = 1; j <= size; ++j) {
      for (int sum = 1; sum <= all_sum; ++sum) {
        dynamic[sum][j] = dynamic[sum][j - 1];
        int num = nums[j - 1];
        
        if (num <= sum) {
          dynamic[sum][j] =
            max(dynamic[sum][j], dynamic[sum - num][j - 1] + num);
        }
      }
    }
    
    return dynamic[all_sum][size] == all_sum;
  }
};

int main() {
  return 0;
}
