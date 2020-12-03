#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  std::string decodeString(std::string s) {
    std::stack<char> work_stack;
    for (char c : s) {
      if (c != ']') {
        work_stack.push(c);
      }
      else {
        std::string repeat_string;
        while (work_stack.top() != '[') {
          repeat_string.push_back(work_stack.top());
          work_stack.pop();
        }
        
        work_stack.pop();
        std::reverse(repeat_string.begin(), repeat_string.end());
        
        std::string repeat_number;
        while (!work_stack.empty() && std::isdigit(work_stack.top())) {
          repeat_number.push_back(work_stack.top());
          work_stack.pop();
        }

        std::reverse(repeat_number.begin(), repeat_number.end());

        for (int i = 0; i < std::stoi(repeat_number); ++i) {
          for (char rc : repeat_string) {
            work_stack.push(rc);
          }
        }
      }
    }

    std::string result;
    while (!work_stack.empty()) {
      result.push_back(work_stack.top());
      work_stack.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  std::string s;
  std::cin >> s;

  Solution solution;
  std::cout << solution.decodeString(s) << std::endl;
  return 0;
}
