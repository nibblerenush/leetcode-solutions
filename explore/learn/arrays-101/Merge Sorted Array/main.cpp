#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    for (int i = m + n - 1; i >= n; --i) {
      nums1[i] = nums1[i - n];
    }
    std::fill(nums1.begin(), nums1.begin() + n, 0);

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
  int m;
  std::cin >> m;
  std::vector<int> nums1(m);
  for (int& num : nums1) {
    std::cin >> num;
  }

  int n;
  std::cin >> n;
  std::vector<int> nums2(n);
  for (int& num : nums2) {
    std::cin >> num;
  }

  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());
  nums1.resize(m + n);
  std::fill(nums1.begin() + m, nums1.end(), 0);

  Solution solution;
  solution.merge(nums1, m, nums2, n);
  for (int num : nums1) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
