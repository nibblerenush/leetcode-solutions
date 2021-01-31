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
  void nextPermutation(vector<int>& nums) {
    // size_t to int
    const int size = nums.size();
    
    int i = size - 1;
    while (i >= 1 && nums[i] <= nums[i - 1]) {
      i -= 1;
    }
    
    if (i != 0) {
      int j = size - 1;
      while (nums[j] <= nums[i - 1]) {
        j -= 1;
      }
      swap(nums[i - 1], nums[j]);
    }

    reverse(nums.begin() + i, nums.end());
  }
};

int main() {
  return 0;
}
