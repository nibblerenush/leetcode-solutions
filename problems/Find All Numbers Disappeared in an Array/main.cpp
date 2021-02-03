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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    // size_t to int
    const int size = nums.size();

    // result
    vector<int> result;

    // init
    int i = 0;
    
    while (i < size) {
      if (nums[i] == i + 1 || nums[i] == 0) {
        ++i;
      }
      else {
        int swap_idx = nums[i] - 1;
        swap(nums[i], nums[swap_idx]);
        if (nums[i] == nums[swap_idx]) {
          nums[i] = 0;
        }
      }
    }
    
    for (i = 0; i < size; ++i) {
      if (nums[i] == 0) {
        result.push_back(i + 1);
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
