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
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hashset;
    for (const auto& num : nums) {
      if (hashset.count(num)) {
        return true;
      }
      hashset.insert(num);
    }
    return false;
  }
};

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  cout << boolalpha << solution.containsDuplicate(nums) << endl;
  return 0;
}
