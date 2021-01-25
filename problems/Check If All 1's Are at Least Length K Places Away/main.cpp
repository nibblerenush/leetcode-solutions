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
  bool kLengthApart(vector<int>& nums, int k) {
    int i = -1;
    int j = 0;
    
    while (j < (int)nums.size()) {
      if (nums[j] == 1) {
        if (i == -1) {
          i = j;
        }
        else {
          int distance = j - i - 1;
          if (distance < k) {
            return false;
          }
          i = j;
        }
      }
      
      j += 1;
    }

    return true;
  }
};

int main() {
  return 0;
}
