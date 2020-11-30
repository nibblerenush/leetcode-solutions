#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> work_stack;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        work_stack.push(c);
      }
      else {
        if (work_stack.empty()) {
          return false;
        }
        else {
          char top = work_stack.top();
          work_stack.pop();

          if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}')) {
            return false;
          }
        }
      }
    }

    return work_stack.empty();
  }
};

int main() {
  std::string s;
  std::cin >> s;

  Solution solution;
  std::cout << std::boolalpha << solution.isValid(s) << std::endl;
  return 0;
}
