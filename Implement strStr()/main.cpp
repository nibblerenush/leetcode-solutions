#include <iostream>
#include <string>

class Solution {
public:
  int strStr(const std::string& haystack, const std::string& needle) {
    if (needle.empty()) {
      return 0;
    }
    
    int haystack_size = haystack.size();
    int needle_size = needle.size();
    
    for (int i = 0; i < haystack_size - needle_size + 1; ++i) {
      bool is_found = true;
      for (int j = 0; j < needle_size; ++j) {
        if (haystack[i + j] != needle[j]) {
          is_found = false;
          break;
        }
      }

      if (is_found) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  std::string haystack, needle;
  std::cin >> haystack >> needle;

  Solution solution;
  std::cout << solution.strStr(haystack, needle) << std::endl;
  return 0;
}
