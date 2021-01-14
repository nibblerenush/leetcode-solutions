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
  vector<int> searchRange(vector<int>& nums, int target) {
    int start = -1;
    int end = -1;
    
    const int size = nums.size();
    if (nums.empty()) {
      return { start, end };
    }
    
    {
      int left = 0;
      int right = size - 1;

      while (left + 1 < right) {
        int mid = left + (right - left) / 2;

        if (is_left_target(nums, mid, target)) {
          start = mid;
          break;
        }
        else if (nums[mid] < target) {
          left = mid;
        }
        else {
          right = mid;
        }
      }

      if (is_left_target(nums, left, target)) {
        start = left;
      }

      if (is_left_target(nums, right, target)) {
        start = right;
      }
    }

    {
      int left = 0;
      int right = size - 1;

      while (left + 1 < right) {
        int mid = left + (right - left) / 2;

        if (is_right_target(nums, mid, target)) {
          end = mid;
          break;
        }
        else if (nums[mid] <= target) {
          left = mid;
        }
        else {
          right = mid;
        }
      }

      if (is_right_target(nums, left, target)) {
        end = left;
      }

      if (is_right_target(nums, right, target)) {
        end = right;
      }
    }
    
    return { start, end };
  }

private:
  bool is_left_target(const vector<int>& nums, int index, int target) {
    int left_index = index - 1;
    bool is_mid_equal = nums[index] == target;
    bool is_left_smaller = left_index >= 0 ? nums[left_index] < target : true;
    return is_mid_equal && is_left_smaller;
  }
  
  bool is_right_target(const vector<int>& nums, int index, int target) {
    int size = nums.size();
    int right_index = index + 1;
    bool is_mid_equal = nums[index] == target;
    bool is_right_bigger = right_index < size ? nums[right_index] > target : true;
    return is_mid_equal && is_right_bigger;
  }
};

int main() {
  return 0;
}
