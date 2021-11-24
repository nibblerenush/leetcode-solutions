#include <algorithm>
#include <cmath>
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
  void rotate(vector<int>& nums, int k) {
    const int nums_size = nums.size();
    k %= nums_size;

    int i = 0;
    int j = nums_size - 1;
    while (i < j) {
      swap(nums[i++], nums[j--]);
    }

    i = 0;
    j = k - 1;
    while (i < j) {
      swap(nums[i++], nums[j--]);
    }

    i = k;
    j = nums_size - 1;
    while (i < j) {
      swap(nums[i++], nums[j--]);
    }
  }
};

int main() {
  return 0;
}
