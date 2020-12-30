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
  int singleNumber(vector<int>& nums) {
    unordered_set<int> hashset;
    int sum_of_nums = 0;
    int sum_of_hashset = 0;

    for (const auto& num : nums) {
      if (!hashset.count(num)) {
        hashset.insert(num);
        sum_of_hashset += num;
      }
      sum_of_nums += num;
    }

    return 2 * sum_of_hashset - sum_of_nums;
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
  cout << solution.singleNumber(nums) << endl;
  return 0;
}
