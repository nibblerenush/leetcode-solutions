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
  int divide(int dividend, int divisor) {
    // edge case 1
    if (dividend == numeric_limits<int>::min()) {
      switch (divisor) {
      case -1:
        return numeric_limits<int>::max();
      case 1:
        return numeric_limits<int>::min();
      }
    }
    
    // edge case 2
    if (divisor == numeric_limits<int>::min()) {
      if (dividend == divisor) {
        return 1;
      }
      else {
        return 0;
      }
    }
    
    // prepare
    int new_divisor = abs(divisor);
    long new_dividend = abs((long)dividend);
    
    int result = 0;
    while (new_dividend >= new_divisor) {
      long division = new_divisor;
      int result_part = 1;
      
      while (division << 1 <= new_dividend) {
        division <<= 1;
        result_part <<= 1;
      }
      
      new_dividend -= division;
      result += result_part;
    }
    
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
      return -result;
    }
    return result;
  }
};

int main() {
  return 0;
}
