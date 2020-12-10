#include <iostream>
#include <vector>

class Solution {
public:
  int kthGrammar(int N, int K) {
    return helper(N, K - 1);
  }

private:
  int helper(int N, int K) {
    if (N == 1) {
      return 0;
    }
    
    int current = helper(N - 1, K / 2);
    std::vector<int> temp;
    if (current == 0) {
      temp = { 0, 1 };
    }
    else {
      temp = { 1, 0 };
    }

    return temp[K % 2];
  }
};

int main() {
  int N = 0, K = 0;
  std::cin >> N >> K;

  Solution solution;
  std::cout << solution.kthGrammar(N, K) << std::endl;
  return 0;
}
