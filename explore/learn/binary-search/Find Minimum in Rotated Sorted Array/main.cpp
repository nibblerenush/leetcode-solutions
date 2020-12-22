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
  int findMin(vector<int>& nums) {
    size = nums.size();
    if (size == 1) {
      return nums[0];
    }

    int left = 0;
    int right = size - 1;

    while (left < right) {
      int mid = (left + right) / 2;
      if (check_is_min(nums, mid)) {
        return nums[mid];
      }
      else if (nums[right] < nums[mid]) {
        left = mid + 1;
      }
      else {
        right = mid;
      }
    }

    if (left != size && check_is_min(nums, left)) {
      return nums[left];
    }
    return -1;
  }

private:
  bool check_is_min(const vector<int>& nums, int index) {
    int left_index = index - 1;
    int right_index = index + 1;

    bool is_left_bigger = left_index >= 0 ? nums[left_index] > nums[index] : nums[size - 1] > nums[index];
    bool is_right_bigger = right_index < size ? nums[right_index] > nums[index] : nums[0] > nums[index];

    return is_left_bigger && is_right_bigger;
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
  cout << solution.findMin(nums) << endl;
  return 0;
}
