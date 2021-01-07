#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int slow = 0;
    int fast = 0;
    int result = 0;
    unordered_set<int> chars_set;
    
    while (fast < (int)s.length()) {
      if (chars_set.count(s[fast])) {
        result = max(result, fast - slow);
        
        while (chars_set.count(s[fast])) {
          chars_set.erase(s[slow++]);
        }
      }
      chars_set.insert(s[fast++]);
    }
    
    result = max(result, fast - slow);
    return result;
  }
};

int main() {
  return 0;
}
