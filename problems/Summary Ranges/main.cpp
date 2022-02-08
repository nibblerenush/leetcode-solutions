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
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if (nums.empty()) {
      return result;
    }
    
    const int size = nums.size();
    int j = 0;
    
    for (int i = 0; i < size; ++i) {
      if (i > 0 && (long)nums[i] - nums[i - 1] > 1) {
        if (j != i - 1) {
          result.push_back(to_string(nums[j]) + "->" + to_string(nums[i - 1]));
        }
        else {
          result.push_back(to_string(nums[j]));
        }
        
        j = i;
      }
    }
    
    if (j != size - 1) {
      result.push_back(to_string(nums[j]) + "->" + to_string(nums[size - 1]));
    }
    else {
      result.push_back(to_string(nums[j]));
    }

    return result;
  }
};

int main() {
  return 0;
}
