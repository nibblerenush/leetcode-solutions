#include <iostream>
#include <string>

class Solution {
public:
  std::string reverseWords(std::string s) {
    int i = 0;
    int j = 0;
    int s_size = s.size();
    
    while (j < s_size) {
      if ((s[j] != ' ') || (j != 0 && s[j - 1] != ' ' && s[j] == ' ')) {
        s[i] = s[j];
        ++i;
      }
      ++j;
    }
    
    s.resize(i);
    if (s.back() == ' ') {
      s.pop_back();
    }
    s_size = s.size();
    
    std::reverse(s.begin(), s.end());
    
    for (j = 0, i = 0; j < s_size; ++j) {
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
