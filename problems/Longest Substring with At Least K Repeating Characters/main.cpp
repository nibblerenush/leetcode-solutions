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
  int longestSubstring(string s, int k) {
    return divide_and_conquer(s, 0, s.length() - 1, k);
  }

private:
  int divide_and_conquer(const string& s, int start, int end, int k) {
    int length = s.length();
    if (start >= 0 && start < length && end >= 0 && end < length && start <= end) {
      unordered_map<char, int> char_count;
      for (int i = start; i <= end; ++i) {
        char_count[s[i]] += 1;
      }
      
      for (int i = start; i <= end; ++i) {
        // Invalid character
        if (char_count[s[i]] < k) {
          return max(
            divide_and_conquer(s, start, i - 1, k),
            divide_and_conquer(s, i + 1, end, k));
        }
      }
      
      return end - start + 1;
    }
    
    return 0;
  }
};

int main() {
  return 0;
}
