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
  int threeSumClosest(vector<int>& nums, int target)
  {
    const int numsSize = nums.size();
    int diff = numeric_limits<int>::max();
    int closestSum = 0;

    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < numsSize - 2; ++i)
    {
      if (i == 0 || nums[i] != nums[i - 1])
      {
        int j = i + 1;
        int k = numsSize - 1;
        
        while (j < k)
        {
          int sum = nums[i] + nums[j] + nums[k];
          if (abs(sum - target) < diff)
          {
            diff = abs(sum - target);
            closestSum = sum;
          }
          
          if (sum < target)
          {
            ++j;
            while (j < numsSize && nums[j] == nums[j - 1]) ++j;
          }
          else if (sum > target)
          {
            --k;
            while (k >= 0 && nums[k] == nums[k + 1]) --k;
          }
          else
          {
            return closestSum;
          }
        }
      }
    }
    
    return closestSum;
  }
};

int main() {
  return 0;
}
