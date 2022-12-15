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
  int countGoodNumbers(long long n) {
    long long fivePow = n / 2 + n % 2;
    long long fourPow = n / 2;
    return binPow(5, fivePow) * binPow(4, fourPow) % modulo;
  }

private:
  long long binPow(long long num, long long pow) {
    long long result = 1;
    while (pow > 0) {
      if (pow % 2 == 1) {
        result = result * num % modulo;
      }
      num = num * num % modulo;
      pow /= 2;
    }
    return result;
  }

private:
  const long long modulo = 1'000'000'007;
};

int main() {
  return 0;
}
