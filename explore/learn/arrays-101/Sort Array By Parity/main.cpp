#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> sortArrayByParity(std::vector<int>& A) {
    int A_size = A.size();
    int i = 0;
    int j = A_size - 1;

    while (i < j) {
      if (A[i] % 2 != 0 && A[j] % 2 == 0) {
        std::swap(A[i++], A[j--]);
      }
      else if (A[i] % 2 == 0) {
        ++i;
      }
      else if (A[j] % 2 != 0) {
        --j;
      }
    }

    return A;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> A(n);
  for (int& num : A) {
    std::cin >> num;
  }

  Solution solution;
  for (int num : solution.sortArrayByParity(A)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
