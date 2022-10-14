#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  string minRemoveToMakeValid(string s) {
    deque<pair<char, size_t>> workStack;
    string tempStr;

    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        tempStr.push_back(c);
      }
      else if (c == '(') {
        tempStr.push_back(c);
        workStack.push_back({ c, tempStr.size() - 1 });
      }
      // c == ')'
      else {
        if (workStack.empty()) {
          continue;
        }

        tempStr.push_back(c);
        workStack.pop_back();
      }
    }

    string resultStr;
    for (size_t i = 0; i < tempStr.length(); ++i) {
      if (!workStack.empty() && workStack.front().second == i) {
        workStack.pop_front();
      }
      else {
        resultStr.push_back(tempStr[i]);
      }
    }

    return resultStr;
  }
};

int main() {
  return 0;
}
