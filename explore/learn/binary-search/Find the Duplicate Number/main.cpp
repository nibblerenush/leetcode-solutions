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
  int findDuplicate(vector<int>& nums) {
    size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 1; i < size; ++i) {
      auto iter = lower_bound(nums.begin(), nums.end(), i);
      if (iter != nums.end()) {
        auto next_iter = next(iter);
        if (next_iter != nums.end() && *next_iter == *iter) {
          return *iter;
        }
      }
    }

    return -1;
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
  cout << solution.findDuplicate(nums) << endl;
  return 0;
}
