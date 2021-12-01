#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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
  return 0;
}
