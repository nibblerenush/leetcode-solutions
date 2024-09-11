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
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> set1(nums1.begin(), nums1.end());
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    
    multiset<int> set2(nums2.begin(), nums2.end());
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

    int count = 0;
    while (sum1 != sum2) {
      ++count;
      const int res = sum1 > sum2 ? helper(set1, sum1, set2, sum2) : helper(set2, sum2, set1, sum1);
      if (res == -1) {
        return -1;
      }
      if (res == 1) {
        return count;
      }
    }

    return count;
  }

private:
  int helper(multiset<int>& set1, int& sum1, multiset<int>& set2, int& sum2) {
    const int diff = sum1 - sum2;
    const int max_inc = 6 - *set2.begin();
    const int max_dec = *prev(set1.end()) - 1;

    if (max_inc == 0 && max_dec <= 0) {
      return -1;
    }

    if (max_inc > max_dec) {
      if (max_inc < diff) {
        set2.erase(set2.begin());
        set2.insert(6);
        sum2 += max_inc;
      }
      else {
        return 1;
      }
    }
    else {
      if (max_dec < diff) {
        set1.erase(prev(set1.end()));
        set1.insert(1);
        sum1 -= max_dec;
      }
      else {
        return 1;
      }
    }

    return 0;
  }
};

int main() {
  return 0;
}
