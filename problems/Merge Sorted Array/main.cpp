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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m + n - 1; i >= n; --i) {
      nums1[i] = nums1[i - n];
    }
    fill(nums1.begin(), nums1.begin() + n, 0);

    int ptr1 = 0;
    int ptr2 = n;
    int ptr3 = 0;

    while (ptr2 < m + n && ptr3 < n) {
      if (nums1[ptr2] < nums2[ptr3]) {
        nums1[ptr1] = nums1[ptr2];
        ptr2++;
      }
      else {
        nums1[ptr1] = nums2[ptr3];
        ptr3++;
      }
      ptr1++;
    }

    while (ptr2 < m + n) {
      nums1[ptr1++] = nums1[ptr2++];
    }

    while (ptr3 < n) {
      nums1[ptr1++] = nums2[ptr3++];
    }
  }
};

int main() {
  return 0;
}
