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
  int myAtoi(string s) {
    // init
    int result = 0;
    
    // size_t to int
    const int length = s.length();
    
    // ignore any leading whitespace
    int i = 0;
    while (i < length && s[i] == ' ') {
      i += 1;
    }
    
    // check if the next character is '-' or '+'
    bool is_positive = true;
    if (i < length && s[i] == '-') {
      i += 1;
      is_positive = false;
    }
    else if (i < length && s[i] == '+') {
      i += 1;
    }
    
    const int max_div_ten = numeric_limits<int>::max() / 10;
    const int min_div_ten = numeric_limits<int>::min() / 10;
    
    // read in next the characters until the next non-digit charcter
    while (i < length && isdigit(s[i])) {
      int digit = s[i] - '0';
      
      if (is_positive) {
        if (result > max_div_ten || (result == max_div_ten && digit > 7)) {
          return numeric_limits<int>::max();
        }
        result = result * 10 + digit;
      }
      else {
        if (result < min_div_ten || (result == min_div_ten && digit > 8)) {
          return numeric_limits<int>::min();
        }
        result = result * 10 - digit;
      }
      
      i += 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
