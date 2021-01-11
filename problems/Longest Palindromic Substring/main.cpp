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
  string longestPalindrome(string s) {
    int max_start = 0;
    int max_length = 1;
    
    for (int i = 0; i < (int)s.length(); ++i) {
      int length = max(get_length(s, i, i), get_length(s, i, i + 1));
      
      if (length > max_length) {
        max_length = length;
        max_start = i - (length - 1) / 2;
      }
    }
    
    return s.substr(max_start, max_length);
  }

private:
  int get_length(const string& s, int start, int end) {
    while (start >= 0 && end < (int)s.length() && s[start] == s[end]) {
      start -= 1;
      end += 1;
    }
    return end - start - 1;
  }
};

int main() {
  return 0;
}
