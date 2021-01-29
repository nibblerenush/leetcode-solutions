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
  int lengthOfLIS(vector<int>& nums) {
    const int size = nums.size();
    
    int result = 0;
    vector<int> dynamic(size, 0);
    
    for (int i = size - 1; i >= 0; --i) {
      int length = 0;
      
      for (int j = i + 1; j < size; ++j) {
        if (nums[j] > nums[i]) {
          length = max(length, dynamic[j]);
        }
      }
      
      dynamic[i] = length + 1;
      result = max(result, dynamic[i]);
    }
    
    return result;
  }
};

int main() {
  return 0;
}
