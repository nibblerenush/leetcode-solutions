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
  void sortColors(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int k = nums.size() - 1;
    
    while (j <= k) {
      if (nums[j] == 0) {
        swap(nums[j++], nums[i++]);
      }
      else if (nums[j] == 2) {
        swap(nums[j], nums[k--]);
      }
      else if (nums[j] == 1) {
        j += 1;
      }
    }
  }
};

int main() {
  return 0;
}
