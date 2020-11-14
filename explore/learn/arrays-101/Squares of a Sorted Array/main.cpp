#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int>& A) {
    int size_a = A.size();
    int i = 0;
    int j = size_a - 1;

    std::vector<int> result(size_a);
    int k = size_a - 1;
    
    while (i <= j) {
      if (std::abs(A[j]) > std::abs(A[i])) {
        result[k--] = std::pow(A[j--], 2);
      }
      else {
        result[k--] = std::pow(A[i++], 2);
      }
    }
    
    return result;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> nums(n);
  for (auto& num : nums) {
    std::cin >> num;
  }
  std::sort(nums.begin(), nums.end());

  Solution solution;
  for (int num : solution.sortedSquares(nums)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
