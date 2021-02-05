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
  string simplifyPath(string path) {
    // size_t to 
    const int length = path.length();
    
    // init
    int i = 1;
    stack<string> work_stack;
    work_stack.push("/");
    
    while (i < length) {
      if (path[i] == '/') {
        if (work_stack.top() != "/") {
          work_stack.push(string(1, path[i]));
        }
        
        i += 1;
      }
      else {
        size_t slash_pos = path.find('/', i);
        string file = slash_pos != string::npos ? path.substr(i, (int)slash_pos - i) : path.substr(i);
        i = slash_pos != string::npos ? slash_pos : path.length();
        
        if (file == ".") {
          continue;
        }
        else if (file == "..") {
          if (work_stack.size() != 1) {
            work_stack.pop(); // slash
            work_stack.pop(); // file
          }
        }
        else {
          work_stack.push(move(file));
        }
      }
    }
    
    // empty stack
    string result;
    while (!work_stack.empty()) {
      if (work_stack.top() == "/") {
        result += move(work_stack.top());
      }
      else {
        string file = move(work_stack.top());
        reverse(file.begin(), file.end());
        result += move(file);
      }
      work_stack.pop();
    }
    
    // post processing
    reverse(result.begin(), result.end());
    if (result.back() == '/' && result.size() != 1) {
      result.pop_back();
    }
    
    return result;
  }
};

int main() {
  return 0;
}
