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
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    const int nums_size = nums.size();

    for (int j = 0; j < nums_size; ++j) {
      if (j == 0 || nums[j] > nums[j - 1]) {
        nums[i++] = nums[j];
      }
    }

    return i;
  }
};

int main() {
  return 0;
}
