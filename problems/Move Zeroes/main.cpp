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
  void moveZeroes(vector<int>& nums) {
    const int size = nums.size();
    int i = -1;
    
    for (int j = 0; j < size; ++j) {
      if (nums[j] != 0) {
        swap(nums[++i], nums[j]);
      }
    }
  }
};

int main() {
  return 0;
}
