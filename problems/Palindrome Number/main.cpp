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
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }
    
    int revertNumber = 0;
    while (x > revertNumber) {
      int mod = x % 10;
      revertNumber = revertNumber * 10 + mod;
      x /= 10;
    }

    return x == revertNumber || x == revertNumber / 10;
  }
};

int main() {
  return 0;
}
