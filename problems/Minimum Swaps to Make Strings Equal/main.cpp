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
  int minimumSwap(string s1, string s2) {
    // s1.length() == s2.length()

    /*
    * [x, x] or [y, y] - 2 pairs with same x and y orientation
    * [y, y]    [x, x]
    * 
    * [x, y] - Need 2 swaps
    * [y, x]
    * 
    * [x, y] - Need 0 swaps
    * [x, y]
    */

    const int len = static_cast<int>(s1.length());

    int xyCount = 0;
    int yxCount = 0;

    for (int i = 0; i < len; ++i) {
      if (s1[i] != s2[i]) {
        if (s1[i] == 'x') {
          ++xyCount;
        }
        else {
          ++yxCount;
        }
      }
    }

    // Odd sum
    if ((xyCount + yxCount) % 2 == 1) {
      return -1;
    }

    // Same orientation
    int swapCount = xyCount / 2 + yxCount / 2;
    if (xyCount % 2 == 1) {
      swapCount += 2;
    }
    
    return swapCount;
  }
};

int main() {
  return 0;
}
