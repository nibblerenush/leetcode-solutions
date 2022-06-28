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
  string removeDuplicateLetters(string s) {
    const int sLen = s.length();
    
    unordered_map<char, int> charsLastIndex;
    for (int i = 0; i < sLen; ++i)
    {
      char c = s[i];
      charsLastIndex[c] = i;
    }

    stack<char> workStack;
    unordered_set<char> usedChars;
    for (int i = 0; i < sLen; ++i)
    {
      char c = s[i];
      if (!usedChars.count(c))
      {
        usedChars.insert(c);
        while (!workStack.empty() && workStack.top() > c && i < charsLastIndex[workStack.top()])
        {
          usedChars.erase(workStack.top());
          workStack.pop();
        }
        workStack.push(c);
      }
    }

    string resStr;
    while (!workStack.empty())
    {
      resStr.push_back(workStack.top());
      workStack.pop();
    }

    reverse(resStr.begin(), resStr.end());
    return resStr;
  }
};

int main() {
  return 0;
}
