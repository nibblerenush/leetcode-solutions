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
  int maximumProduct(vector<int>& nums) {
    const int size = nums.size();
    sort(nums.begin(), nums.end());
    int productBegin = nums[0] * nums[1] * nums.back();
    int productEnd = nums[size - 1] * nums[size - 2] * nums[size - 3];
    return max(productBegin, productEnd);
  }
};

int main() {
  return 0;
}
