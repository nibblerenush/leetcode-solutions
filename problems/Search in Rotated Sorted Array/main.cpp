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
  int search(vector<int>& nums, int target) {
    int size = nums.size();
    
    int left = 0;
    int right = size - 1;
    int pivot_index = 0;
    
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      
      if (check_is_pivot(nums, mid)) {
        pivot_index = mid;
        break;
      }
      else if (nums[left] < nums[mid]) {
        left = mid;
      }
      else {
        right = mid;
      }
    }
    
    if (check_is_pivot(nums, left)) {
      pivot_index = left;
    }
    
    if (check_is_pivot(nums, right)) {
      pivot_index = right;
    }
    
    auto left_iter = lower_bound(nums.begin(), nums.begin() + pivot_index, target);
    if (left_iter != nums.end() && *left_iter == target) {
      return distance(nums.begin(), left_iter);
    }
    
    auto right_iter = lower_bound(nums.begin() + pivot_index, nums.end(), target);
    if (right_iter != nums.end() && *right_iter == target) {
      return distance(nums.begin(), right_iter);
    }
    
    return -1;
  }

private:
  bool check_is_pivot(const vector<int>& nums, int index) {
    int size = nums.size();
    return index - 1 >= 0 ? nums[index - 1] > nums[index] : nums[size - 1] > nums[index];
  }
};

int main() {
  return 0;
}
