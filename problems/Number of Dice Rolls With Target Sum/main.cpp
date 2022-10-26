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
  int numRollsToTarget(int n, int k, int target) {
    memorization =
      vector<vector<int>>(maxDices + 1, vector<int>(maxTarget + 1, 0));
    return func(n, k, target);
  }

private:
  int func(int n, int k, int target) {
    if (n == 0) {
      return target == 0 ? 1 : 0;
    }
    
    if (target < 0) {
      return 0;
    }
    
    if (memorization[n][target] != 0) {
      return memorization[n][target] - 1;
    }
    
    int result = 0;
    for (int face = 1; face <= k; ++face) {
      result = (result + func(n - 1, k, target- face)) % 1'000'000'007;
    }
    
    // result cat be zero
    memorization[n][target] = result + 1;
    
    return result;
  }

private:
  static const int maxDices = 30;
  static const int maxTarget = 1000;
  vector<vector<int>> memorization;
};

int main() {
  return 0;
}
