#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<std::string> work_stack;

    for (const auto& token : tokens) {
      if (!isSign(token)) {
        work_stack.push(token);
      }
      else {
        std::string num1 = work_stack.top();
        work_stack.pop();
        
        std::string num2 = work_stack.top();
        work_stack.pop();
        
        if (token == "+") {
          int oper_result = std::stoi(num2) + std::stoi(num1);
          work_stack.push(std::to_string(oper_result));
        }
        else if (token == "-") {
          int oper_result = std::stoi(num2) - std::stoi(num1);
          work_stack.push(std::to_string(oper_result));
        }
        else if (token == "*") {
          int oper_result = std::stoi(num2) * std::stoi(num1);
          work_stack.push(std::to_string(oper_result));
        }
        else if (token == "/") {
          int oper_result = std::stoi(num2) / std::stoi(num1);
          work_stack.push(std::to_string(oper_result));
        }
      }
    }
    
    return std::stoi(work_stack.top());
  }

private:
  bool isSign(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<std::string> tokens(n);
  for (auto& token : tokens) {
    std::cin >> token;
  }

  Solution solution;
  std::cout << solution.evalRPN(tokens) << std::endl;
  return 0;
}
