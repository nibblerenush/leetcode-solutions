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
  uint32_t reverseBits(uint32_t n) {
    uint32_t reversed_n = 0;
    const int bits_count = 32;

    for (int i = 0; i < bits_count; ++i) {
      int bit_value = n & 1;
      n >>= 1;

      reversed_n <<= 1;
      reversed_n |= bit_value;
    }

    return reversed_n;
  }
};

int main() {
  return 0;
}
