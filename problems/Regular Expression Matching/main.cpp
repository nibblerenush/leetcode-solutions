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
  bool isMatch(string s, string p) {
    return backtrack(s, 0, p, 0);
  }

private:
  bool backtrack(const string& text, int i, const string& pattern, int j) {
    if (j >= (int)pattern.length()) {
      return i >= (int)text.length();
    }
    
    bool first_match = i < (int)text.length() && (text[i] == pattern[j] || pattern[j] == '.');
    if (j < (int)pattern.length() - 1 && pattern[j + 1] == '*') {
      return (backtrack(text, i, pattern, j + 2)) || (first_match && backtrack(text, i + 1, pattern, j));
    }
    else {
      return first_match && backtrack(text, i + 1, pattern, j + 1);
    }
  }
};

int main() {
  return 0;
}
