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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < (int)nums.size() - 2; ++i) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        for (int j = i + 1; j < (int)nums.size() - 1; ++j) {
          if (j == i + 1 || nums[j] != nums[j - 1]) {
            int num = -nums[i] - nums[j];
            if (binary_search(nums.begin() + j + 1, nums.end(), num)) {
              result.push_back({ nums[i], nums[j], num });
            }
          }
        }
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
