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
  int evalRPN(vector<string>& tokens) {
    stack<string> work_stack;

    for (const auto& token : tokens) {
      if (!isSign(token)) {
        work_stack.push(token);
      }
      else {
        string num1 = work_stack.top();
        work_stack.pop();
        
        string num2 = work_stack.top();
        work_stack.pop();
        
        if (token == "+") {
          int oper_result = stoi(num2) + stoi(num1);
          work_stack.push(to_string(oper_result));
        }
        else if (token == "-") {
          int oper_result = stoi(num2) - stoi(num1);
          work_stack.push(to_string(oper_result));
        }
        else if (token == "*") {
          int oper_result = stoi(num2) * stoi(num1);
          work_stack.push(to_string(oper_result));
        }
        else if (token == "/") {
          int oper_result = stoi(num2) / stoi(num1);
          work_stack.push(to_string(oper_result));
        }
      }
    }
    
    return stoi(work_stack.top());
  }

private:
  bool isSign(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }
};

int main() {
  return 0;
}
