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
  bool isValid(string s) {
    stack<char> work_stack;
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
  return 0;
}
