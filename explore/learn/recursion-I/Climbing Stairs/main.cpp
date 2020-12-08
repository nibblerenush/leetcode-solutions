#include <iostream>
#include <unordered_map>

class Solution {
public:
  int climbStairs(int n) {
    if (cache.count(n)) {
      return cache[n];
    }

    int result = 0;
    if (n < 2) {
      result = 1;
    }
    else {
      result = climbStairs(n - 1) + climbStairs(n - 2);
    }

    cache[n] = result;
    return result;
  }

private:
  std::unordered_map<int, int> cache;
};

int main() {
  int n = 0;
  std::cin >> n;

  Solution solution;
  std::cout << solution.climbStairs(n) << std::endl;
  return 0;
}
