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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    
    int left = 0;
    int right = m;

    while (left <= right) {
      int part_m = (left + right) / 2;
      int part_n = (m + n + 1) / 2 - part_m;

      int maxLeft_m = part_m > 0 ? nums1[part_m - 1] : numeric_limits<int>::min();
      int minRight_m = part_m < m ? nums1[part_m] : numeric_limits<int>::max();

      int maxLeft_n = part_n > 0 ? nums2[part_n - 1] : numeric_limits<int>::min();
      int minRight_n = part_n < n ? nums2[part_n] : numeric_limits<int>::max();

      if (maxLeft_m <= minRight_n && maxLeft_n <= minRight_m) {
        if ((m + n) % 2 == 0) {
          return (static_cast<double>(max(maxLeft_m, maxLeft_n)) + min(minRight_m, minRight_n)) / 2;
        }
        return max(maxLeft_m, maxLeft_n);
      }
      else if (maxLeft_m > minRight_n) {
        right = part_m - 1;
      }
      else {
        left = part_m + 1;
      }
    }
    return -1;
  }
};

int main() {
  int m, n;
  cin >> m >> n;
  
  vector<int> nums1(m);
  for (auto& num : nums1) {
    cin >> num;
  }

  vector<int> nums2(n);
  for (auto& num : nums2) {
    cin >> num;
  }
  
  Solution solution;
  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
