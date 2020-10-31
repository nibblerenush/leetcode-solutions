#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
      return {};
    }
    
    int lcp_size = 0;
    
    for (std::size_t j = 0; j < strs[0].size(); ++j) {
      for (std::size_t i = 1; i < strs.size(); ++i) {
        if (strs[0][j] != strs[i][j]) {
          return strs[0].substr(0, lcp_size);
        }
      }
      lcp_size++;
    }
    
    return lcp_size ? strs[0].substr(0, lcp_size) : std::string{};
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<std::string> strs(n);
  for (auto& str : strs) {
    std::cin >> str;
  }
  
  Solution solution;
  std::cout << solution.longestCommonPrefix(strs) << std::endl;
  return 0;
}
