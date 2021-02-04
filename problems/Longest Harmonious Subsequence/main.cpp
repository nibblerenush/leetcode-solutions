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
  int findLHS(vector<int>& nums) {
    // init helpers
    map<int, int> num_count;
    int result = 0;
    
    for (int num : nums) {
      num_count[num] += 1;
    }
    
    auto iter = num_count.begin();
    while (iter != prev(num_count.end())) {
      if (next(iter)->first - iter->first == 1) {
        result = max(result, next(iter)->second + iter->second);
      }
      ++iter;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
