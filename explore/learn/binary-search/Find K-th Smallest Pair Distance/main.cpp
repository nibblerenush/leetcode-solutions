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
  int smallestDistancePair(vector<int>& nums, int k) {
    size = nums.size();
    sort(nums.begin(), nums.end());
    
    int left = 0;
    int right = nums.back() - nums[0];
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (number_of_pairs_less_than_value(nums, mid) < k) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    return left;
  }

private:
  int number_of_pairs_less_than_value(const vector<int>& nums, int value) {
    // sliding window
    int count = 0;
    for (int left = 0, right = 1; left < size; ++left) {
      while (right < size && nums[right] - nums[left] <= value) {
        ++right;
      }
      count += (right - left - 1);
    }
    return count;
  }

private:
  int size = 0;
};

int main() {
  int k, n;
  cin >> k >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << solution.smallestDistancePair(nums, k) << endl;
  return 0;
}
