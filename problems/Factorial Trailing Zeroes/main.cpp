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
  int trailingZeroes(int n) {
    int result = 0;

    int div = 5;
    while (n / div > 0) {
      result += n / div;
      div *= 5;
    }

    return result;
  }
};

int main() {
  return 0;
}
