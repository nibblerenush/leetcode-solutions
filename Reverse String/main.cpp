#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void reverseString(std::vector<char>& s) {
    int i = 0;
    int j = static_cast<int>(s.size()) - 1;

    while (i < j) {
      std::swap(s[i++], s[j--]);
    }
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<char> s(n);
  for (auto& c : s) {
    std::cin >> c;
  }

  Solution solution;
  solution.reverseString(s);
  for (auto c : s) {
    std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}
