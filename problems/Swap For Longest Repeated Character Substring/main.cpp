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
  int maxRepOpt1(string text) {
    const int n = static_cast<int>(text.length());
    
    unordered_map<char, int> charCount;
    for (char c : text) {
      ++charCount[c];
    }
    
    int i = 0;
    char mainS = text[i];
    int j = i + 1;
    bool between = false;
    
    int newI = 0;
    int maxLen = 1;
    
    while (j < n) {
      if (text[j] == mainS) {
        ++j;
      }
      else {
        if (!between && j + 1 < n && text[j + 1] == mainS) {
          newI = j;
          ++j;
          between = true;
        }
        else {
          int newLen = j - i;
          if (between) {
            if (charCount[mainS] - (newLen - 1) == 0) {
              --newLen;
            }
          }
          else {
            newI = j;
            if ((i - 1 >= 0 || j + 1 < n) && charCount[mainS] - newLen > 0) {
              ++newLen;
            }
          }
          maxLen = max(maxLen, newLen);

          i = newI;
          mainS = text[i];
          j = i + 1;
          between = false;
        }
      }
    }

    // Post processing
    int newLen = j - i;
    if (between) {
      if (charCount[mainS] - (newLen - 1) == 0) {
        --newLen;
      }
    }
    else {
      if ((i - 1 >= 0 || j + 1 < n) && charCount[mainS] - newLen > 0) {
        ++newLen;
      }
    }
    maxLen = max(maxLen, newLen);

    return maxLen;
  }
};

int main() {
  return 0;
}
