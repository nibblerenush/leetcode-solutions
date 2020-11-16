#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> replaceElements(std::vector<int>& arr) {
    int arr_size = arr.size();
    int max = arr[arr_size - 1];
    
    for (int i = arr_size - 2; i >= 0; --i) {
      int old_max = max;
      max = std::max(max, arr[i]);
      arr[i] = old_max;
    }
    arr[arr_size - 1] = -1;

    return arr;
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
  for (int num : solution.replaceElements(arr)) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;
  return 0;
}
