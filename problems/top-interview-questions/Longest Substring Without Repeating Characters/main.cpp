#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<int> chars;
    int begin = 0;
    int end = 0;
    int result = 0;
    
    while (end < static_cast<int>(s.length())) {
      if (chars.count(s[end])) {
        if (end - begin > result) {
          result = end - begin;
        }
        
        while (s[begin] != s[end]) {
          chars.erase(s[begin++]);
        }
        begin++;
      }
      chars.insert(s[end++]);
    }
    
    if (end - begin > result) {
      result = end - begin;
    }

    return result;
  }
};

int main() {
  std::string s = "abcabcbb";

  Solution solution;
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
  return 0;
}
