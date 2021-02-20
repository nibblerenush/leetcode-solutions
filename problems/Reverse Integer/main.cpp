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
  int reverse(int x) {
    const int max = numeric_limits<int>::max() / 10;
    const int max_digit = numeric_limits<int>::max() % 10;
    const int min_digit = abs(numeric_limits<int>::min()) % 10;
    
    int result = 0;
    while (x) {
      if (result == numeric_limits<int>::max() || result == numeric_limits<int>::min()) {
        return 0;
      }
      
      int digit = x % 10;
      x /= 10;
      
      if (abs(result) > max) {
        return 0;
      }
      else {
        if (abs(result) == max) {
          if (x < 0 && abs(digit) > min_digit) {
            return 0;
          }
          
          if (x > 0 && digit > max_digit) {
            return 0;
          }
        }
        
        result *= 10;
        result += digit;
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
