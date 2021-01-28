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
  int concatenatedBinary(int n) {
    const int mod = 1'000'000'007;
    long long result = 0;
    
    // f(num) - result in num
    // length(num) - bit length of num
    // f(num) = f(num - 1) << length(num) + num
    
    // (a + b) mod m = (a mod m + b mod m) mod m
    // f(n) mod m = (f(n - 1) << l(n) + n) mod m = ((f(n - 1) << l(n)) mod m + n mod m) mod m;
    
    for (int num = 1; num <= n; ++num) {
      result = ((result << length(num)) % mod + num % mod) % mod;
    }

    return result;
  }

private:
  int length(int num) {
    int length = 0;
    while (num) {
      length += 1;
      num >>= 1;
    }
    return length;
  }
};

int main() {
  return 0;
}
