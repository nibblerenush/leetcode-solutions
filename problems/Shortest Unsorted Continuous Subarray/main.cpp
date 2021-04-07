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
  int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();
    int min_unsorted = numeric_limits<int>::max();
    int max_unsorted = numeric_limits<int>::min();
    
    for (int i = 0; i < size; ++i) {
      if ((i + 1 < size ? nums[i] > nums[i + 1] : false) || (i - 1 >= 0 ? nums[i] < nums[i - 1] : false)) {
        min_unsorted = min(min_unsorted, nums[i]);
        max_unsorted = max(max_unsorted, nums[i]);
      }
    }
    
    int start = 0;
    int end = 0;
    
    for (int i = 0; i < size; ++i) {
      if (nums[i] > min_unsorted) {
        start = i;
        break;
      }
    }
    
    for (int i = size - 1; i >= 0; --i) {
      if (nums[i] < max_unsorted) {
        end = i;
        break;
      }
    }
    
    if (start == end) {
      return 0;
    }
    return end - start + 1;
  }
};

int main() {
  return 0;
}
