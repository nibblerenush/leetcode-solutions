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
  int monotoneIncreasingDigits(int n) {
    const string nStr = to_string(n);
    const int nStrLen = nStr.length();
    string resStr;
    
    int i = 0;
    for (; i < nStrLen; ++i) {
      char c = nStr[i];
      if (i == 0 || nStr[i] >= nStr[i - 1]) {
        resStr.push_back(c);
      }
      else {
        break;
      }
    }
    
    if (i < nStrLen) {
      for (int j = i - 1; j >= 0; --j)
      {
        --resStr[j];
        if (j == 0 || resStr[j] >= resStr[j - 1]) {
          break;
        }
        resStr[j] = '9';
      }

      long resNum = stol(resStr);
      while (true) {
        resNum = resNum * 10 + 9;
        if (resNum > n) {
          resNum /= 10;
          break;
        }
      }

      return resNum;
    }

    return stoi(resStr);
  }
};

int main() {
  return 0;
}
