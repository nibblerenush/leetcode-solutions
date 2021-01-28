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
  int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < size - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        return nums[i];
      }
    }
    
    return -1;
  }
};

int main() {
  return 0;
}
