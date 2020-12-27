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
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> intersections;
    auto iter1 = nums1.begin();
    while (iter1 != nums1.end()) {
      int old_value = *iter1;

      if (binary_search(nums2.begin(), nums2.end(), *iter1)) {
        auto iter2 = lower_bound(nums2.begin(), nums2.end(), *iter1);
        while (iter1 != nums1.end() && iter2 != nums2.end() && *iter1 == *iter2 && *iter1 == old_value) {
          intersections.push_back(*iter1);
          ++iter1;
          ++iter2;
        }
      }

      while (iter1 != nums1.end() && *iter1 == old_value) {
        ++iter1;
      }
    }

    return intersections;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nums1(n);
  for (auto& num : nums1) {
    cin >> num;
  }

  vector<int> nums2(m);
  for (auto& num : nums2) {
    cin >> num;
  }
  
  Solution solution;
  auto intersections = solution.intersect(nums1, nums2);
  for (const auto& num : intersections) {
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}
