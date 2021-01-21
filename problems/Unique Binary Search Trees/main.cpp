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
  int numTrees(int n) {
    vector<int> dynamic(n + 1);
    dynamic[0] = 1;
    dynamic[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int root = 1; root <= i; ++root) {
        dynamic[i] += dynamic[root - 1] * dynamic[i - root];
      }
    }

    return dynamic[n];
  }
};

int main() {
  return 0;
}
