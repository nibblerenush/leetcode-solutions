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
  int titleToNumber(string columnTitle) {
    const int base = 26;
    long long base_to_power = 1;
    long long result = 0;

    for (int i = (int)columnTitle.length() - 1; i >= 0; --i) {
      result += ((long long)columnTitle[i] - 'A' + 1) * base_to_power;
      base_to_power *= base;
    }

    return result;
  }
};

int main() {
  return 0;
}
