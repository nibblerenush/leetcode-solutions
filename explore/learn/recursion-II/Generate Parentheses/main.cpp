#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> parentheses;
    
    stack<pair<int, int>> open_close_stack;
    open_close_stack.push({ 0, 0 });
    
    stack<string> parentheses_stack;
    parentheses_stack.push("");
    
    while (!open_close_stack.empty()) {
      int open = open_close_stack.top().first;
      int close = open_close_stack.top().second;
      string parenthese = parentheses_stack.top();
      
      open_close_stack.pop();
      parentheses_stack.pop();
      
      if (close > open || open > n || close > n) {
        continue;
      }
      
      if (open + close == 2 * n) {
        parentheses.push_back(parenthese);
      }

      parentheses_stack.push(parenthese + '(');
      open_close_stack.push({ open + 1, close });

      parentheses_stack.push(parenthese + ')');
      open_close_stack.push({ open, close + 1 });
    }
    return parentheses;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  Solution solution;
  auto parentheses = solution.generateParenthesis(n);
  for (const auto& parenthese : parentheses) {
    for (char c : parenthese) {
      std::cout << c;
    }
    std::cout << '\n';
  }
  return 0;
}
