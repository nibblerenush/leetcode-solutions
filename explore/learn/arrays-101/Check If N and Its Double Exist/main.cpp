#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool checkIfExist(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    int arr_size = arr.size();

    for (int i = 0; i < arr_size - 1; ++i) {
      int double_num = 2 * arr[i];
      std::vector<int>::iterator iter;
      if (double_num >= 0) {
        iter = std::lower_bound(arr.begin() + i + 1, arr.end(), double_num);
      }
      else {
        iter = std::lower_bound(arr.begin(), arr.begin() + i, double_num);
      }

      if (iter != arr.end() && *iter == double_num) {
        return true;
      }
    }

    return false;
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
  std::cout << std::boolalpha << solution.checkIfExist(arr) << std::endl;
  return 0;
}
