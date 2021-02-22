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
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return {};
    }
    
    int lcp_size = 0;
    for (int j = 0; j < (int)strs[0].size(); ++j) {
      for (int i = 1; i < (int)strs.size(); ++i) {
        if (strs[0][j] != strs[i][j]) {
          return strs[0].substr(0, lcp_size);
        }
      }
      lcp_size += 1;
    }
    
    return lcp_size ? strs[0].substr(0, lcp_size) : string{};
  }
};

int main() {
  return 0;
}
