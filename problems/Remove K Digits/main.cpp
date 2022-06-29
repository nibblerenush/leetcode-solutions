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
  string removeKdigits(string num, int k) {
    const int numLen = num.length();
    const int minNumLen = numLen - k;
    
    deque<char> wDeque;
    for (int i = 0; i < numLen; ++i)
    {
      char c = num[i];
      int tailSize = numLen - i;
      while (!wDeque.empty() && wDeque.back() > c && tailSize > minNumLen - (int)wDeque.size())
      {
        wDeque.pop_back();
      }
      
      if (wDeque.size() < minNumLen)
      {
        wDeque.push_back(c);
      }
    }

    while (!wDeque.empty() && wDeque.front() == '0') wDeque.pop_front();
    return wDeque.empty() ? "0" : string(wDeque.begin(), wDeque.end());
  }
};

int main() {
  return 0;
}
