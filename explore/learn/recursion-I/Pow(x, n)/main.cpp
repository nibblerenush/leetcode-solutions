#include <cmath>
#include <iostream>

class Solution {
public:
  double myPow(double x, int n) {
    double temp = helper(x, std::abs(static_cast<long long>(n)), 1);
    return n < 0 ? 1 / temp : temp;
  }

private:
  double helper(double x, long long n, double temp) {
    if (n == 0) {
      return temp;
    }
    
    if (n & 1) {
      temp *= x;
    }
    
    return helper(x * x, n >> 1, temp);
  }
};

int main() {
  double x = 0.0;
  int n = 0;
  std::cin >> x >> n;

  Solution solution;
  std::cout << solution.myPow(x, n) << std::endl;
  return 0;
}
