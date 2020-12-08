#include <iostream>
#include <unordered_map>

class Solution {
public:
  int fib(int N) {
    if (cache.count(N)) {
      return cache[N];
    }

    int result = 0;
    if (N < 2) {
      result = N;
    }
    else {
      result = fib(N - 1) + fib(N - 2);
    }

    cache[N] = result;
    return result;
  }

private:
  std::unordered_map<int, int> cache;
};

int main() {
  int N = 0;
  std::cin >> N;

  Solution solution;
  std::cout << solution.fib(N) << std::endl;
  return 0;
}
