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
  int integerBreak(int n) {
    int product = 1;

    if (n == 2) {
      return 1;
    }
    else if (n == 3) {
      return 2;
    }
    else {
      while (n != 0) {
        if (abs(n - 3) != 1) {
          product *= 3;
          n -= 3;
        }
        else {
          product *= 2;
          n -= 2;
        }
      }
    }

    return product;
  }
};

int main() {
  return 0;
}
