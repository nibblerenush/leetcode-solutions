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
  int countSubstrings(string s) {
    // size_t to int
    const int length = s.length();
    
    // init result
    int result = 0;
    
    for (int i = 0; i < length; ++i) {
      result +=
        count_from_index(s, i, i) +
        count_from_index(s, i, i + 1);
    }
    
    return result;
  }

private:
  int count_from_index(const string& s, int start, int end) {
    int count = 0;
    while (start >= 0 && end < (int)s.length() && s[start] == s[end]) {
      count += 1;
      start -= 1;
      end += 1;
    }
    return count;
  }
};

int main() {
  return 0;
}
