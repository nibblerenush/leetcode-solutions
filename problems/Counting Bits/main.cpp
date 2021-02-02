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
  vector<int> countBits(int num) {
    // init
    vector<int> result;
    result.push_back(0);
    
    // edge case
    if (num == 0) {
      return result;
    }
    
    int cur_pow = 1;
    int prev_pow = cur_pow;
    int j = prev_pow;
    int next_pow = cur_pow << 1;
    
    for (int i = 1; i <= num; ++i) {
      if (i == next_pow) {
        cur_pow = next_pow;
        prev_pow = cur_pow >> 1;
        j = prev_pow;
        next_pow <<= 1;
      }
      
      if (j < cur_pow) {
        result.push_back(result[j++]);
      }
      else {
        result.push_back(result[j++ - prev_pow] + 1);
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
