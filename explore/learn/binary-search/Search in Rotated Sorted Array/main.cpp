#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
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
    
    while (left <= right) {
      int mid = (left + right) / 2;
      
      if (check_is_pivot(nums, mid)) {
        pivot_index = mid;
        break;
      }
      else if (nums[left] <= nums[mid]) {
        if (check_is_pivot(nums, left)) {
          pivot_index = left;
          break;
        }
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    
    int left_index = binary_search(nums, 0, pivot_index - 1, target);
    int right_index = binary_search(nums, pivot_index, size - 1, target);
    if (left_index == -1 && right_index == -1) {
      return -1;
    }
    else if (left_index == -1) {
      return right_index;
    }
    return left_index;
  }

private:
  int binary_search(const vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      else if (target < nums[mid]) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return -1;
  }
  
  bool check_is_pivot(const vector<int>& nums, int index) {
    return index - 1 >= 0 && nums[index - 1] > nums[index];
  }

private:
  int size = 0;
};

int main() {
  int target, n;
  cin >> target >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << solution.search(nums, target) << endl;
  return 0;
}
