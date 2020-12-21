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
    if (nums.empty()) {
      return -1;
    }

    int left = 0;
    int right = nums.size() - 1;
    
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
