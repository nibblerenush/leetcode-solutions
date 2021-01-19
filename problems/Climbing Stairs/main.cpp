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
  int climbStairs(int n) {
    if (n == 0) {
      return 0;
    }

    vector<int> dynamic(n + 1, 0);
    dynamic[0] = 1;
    dynamic[1] = 1;

    for (int i = 2; i <= n; ++i) {
      dynamic[i] = dynamic[i - 1] + dynamic[i - 2];
    }

    return dynamic[n];
  }
};

int main() {
  return 0;
}
