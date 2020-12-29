#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    size = nums.size();
    
    int left = 0;
    int right = accumulate(nums.begin(), nums.end(), 0);
    int result = 0;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      
      if (check_value_is_max_sum(nums, mid, m)) {
        result = mid;
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }

    return result;
  }

private:
  bool check_value_is_max_sum(const vector<int>& nums, int value, int m) {
    int count = 0;
    int subarray_sum = 0;
    
    for (int i = 0; i < size; ++i) {
      if (nums[i] > value) {
        return false;
      }
      
      subarray_sum += nums[i];
      if (subarray_sum > value) {
        ++count;
        subarray_sum = nums[i];
      }
    }
    ++count;

    return count <= m;
  }

private:
  int size = 0;
};

int main() {
  int m, n;
  cin >> m >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << solution.splitArray(nums, m) << endl;
  return 0;
}
