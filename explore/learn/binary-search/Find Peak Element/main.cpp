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
  int findPeakElement(vector<int>& nums) {
    size = nums.size();
    
    int left = 0;
    int right = size;

    while (left < right) {
      int mid = (left + right) / 2;
      if (check_is_peak(nums, mid)) {
        return mid;
      }
      else if (mid + 1 < size && nums[mid + 1] > nums[mid]) {
        left = mid + 1;
      }
      else {
        right = mid;
      }
    }

    if (left != size && check_is_peak(nums, left)) {
      return left;
    }
    return -1;
  }

private:
  bool check_is_peak(const vector<int>& nums, int index) {
    int left_index = index - 1;
    int right_index = index + 1;

    bool is_left_smaller = left_index >= 0 ? nums[left_index] < nums[index] : true;
    bool is_right_smaller = right_index < size ? nums[right_index] < nums[index] : true;

    return is_left_smaller && is_right_smaller;
  }

private:
  int size = 0;
};

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << solution.findPeakElement(nums) << endl;
  return 0;
}
