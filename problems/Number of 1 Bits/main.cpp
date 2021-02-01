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
  int hammingWeight(uint32_t n) {
    // init result
    int result = 0;

    for (int i = 0; i < 8 * sizeof(n); ++i) {
      result += n & 1;
      n >>= 1;
    }

    return result;
  }
};

int main() {
  return 0;
}
