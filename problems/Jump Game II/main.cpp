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
  int jump(vector<int>& nums) {
    int nums_size = nums.size();
    // Fill with unreachable value
    vector<int> reach_from_index(nums_size, -1);
    // Not consider first element
    reach_from_index[0] = -2;
    
    for (int i = 0; i < nums_size - 1; ++i) {
      int j = i + nums[i] < nums_size ? i + nums[i] : nums_size - 1;
      while (reach_from_index[j] == -1) {
        reach_from_index[j] = i;
        j -= 1;
      }
      
      if (j == nums_size - 1) {
        break;
      }
    }
    
    int jump_count = 0;
    int i = nums_size - 1;
    while (i != 0) {
      jump_count += 1;
      i = reach_from_index[i];
    }
    
    return jump_count;
  }
};

int main() {
  return 0;
}
