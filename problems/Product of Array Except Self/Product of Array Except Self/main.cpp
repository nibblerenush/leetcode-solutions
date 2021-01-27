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
  vector<int> productExceptSelf(vector<int>& nums) {
    const int size = nums.size();
    
    vector<int> result(size);
    for (int i = 0; i < size; ++i) {
      result[i] = nums[i] * (i > 0 ? result[i - 1] : 1);
    }
    
    int suffix = 1;
    for (int i = size - 1; i >= 0; --i) {
      suffix *= (i < size - 1 ? nums[i + 1] : 1);
      result[i] = (i > 0 ? result[i - 1] : 1) * suffix;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
