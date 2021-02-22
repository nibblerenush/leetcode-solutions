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
  int romanToInt(string s) {
    const unordered_map<char, int> roman_to_int = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };

    int result = 0;
    int i = s.length() - 1;

    auto parse_roman = [&s, &roman_to_int, &result, &i](char prev_roman) {
      if (i == 0 || s[i - 1] != prev_roman) {
        result += roman_to_int.at(s[i--]);
      }
      else {
        result += roman_to_int.at(s[i]) - roman_to_int.at(prev_roman);
        i -= 2;
      }
    };

    while (i >= 0) {
      switch (s[i]) {
      case 'I':
        result += roman_to_int.at(s[i--]);
        break;
      case 'V':
      case 'X':
        parse_roman('I');
        break;
      case 'L':
      case 'C':
        parse_roman('X');
        break;
      case 'D':
      case 'M':
        parse_roman('C');
        break;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
