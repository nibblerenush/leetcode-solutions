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
  int strStr(string haystack, string needle) {
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
  return 0;
}
