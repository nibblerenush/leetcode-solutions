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
  double myPow(double x, int n) {
    if (n >= 0) {
      return non_negative_my_pow(x, n);
    }
    return 1.0 / non_negative_my_pow(x, n);
  }

private:
  double non_negative_my_pow(double x, int n) {
    if (n == 0) {
      return 1;
    }

    if (n % 2 == 0) {
      return non_negative_my_pow(x * x, n / 2);
    }
    else {
      return x * non_negative_my_pow(x * x, n / 2);
    }
  }
};

int main() {
  return 0;
}
