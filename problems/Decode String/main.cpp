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
  string decodeString(string s) {
    // init
    stack<char> work_stack;
    
    for (char c : s) {
      if (c != ']') {
        work_stack.push(c);
      }
      else {
        string repeat_string;
        while (work_stack.top() != '[') {
          repeat_string.push_back(work_stack.top());
          work_stack.pop();
        }
        
        work_stack.pop();
        reverse(repeat_string.begin(), repeat_string.end());
        
        string repeat_number;
        while (!work_stack.empty() && isdigit(work_stack.top())) {
          repeat_number.push_back(work_stack.top());
          work_stack.pop();
        }
        
        reverse(repeat_number.begin(), repeat_number.end());
        
        for (int i = 0; i < stoi(repeat_number); ++i) {
          for (char rc : repeat_string) {
            work_stack.push(rc);
          }
        }
      }
    }
    
    string result;
    while (!work_stack.empty()) {
      result.push_back(work_stack.top());
      work_stack.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  return 0;
}
