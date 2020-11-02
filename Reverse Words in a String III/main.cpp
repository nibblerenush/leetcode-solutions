#include <iostream>
#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    int i = 0;
    const int s_size = s.size();
    for (int j = 0; j < s_size; ++j) {
      if (s[j] == ' ') {
        std::reverse(s.begin() + i, s.begin() + j);
        i = j + 1;
      }
    }
    std::reverse(s.begin() + i, s.end());
    return s;
  }
};

int main() {
  std::string s;
  std::getline(std::cin, s);

  Solution solution;
  std::cout << solution.reverseWords(s) << std::endl;
  return 0;
}
