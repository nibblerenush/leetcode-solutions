#include <iostream>
#include <vector>

class Solution {
public:
  void duplicateZeros(std::vector<int>& arr) {
    int i = 0;
    int arr_size = arr.size();
    
    while (i < arr_size) {
      if (arr[i] == 0) {
        for (int j = arr_size - 1; j > i; --j) {
          arr[j] = arr[j - 1];
        }
        i += 2;
      }
      else {
        ++i;
      }
    }
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int& num : arr) {
    std::cin >> num;
  }

  Solution solution;
  solution.duplicateZeros(arr);
  for (int num : arr) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
