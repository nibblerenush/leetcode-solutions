#include <iostream>
#include <vector>

class Solution {
public:
  bool validMountainArray(std::vector<int>& arr) {
    int arr_size = arr.size();
    if (arr_size < 3 || arr[0] >= arr[1] || arr[arr_size - 2] <= arr[arr_size - 1]) {
      return false;
    }

    int peak = 0;
    for (int i = 1; i < arr_size - 1; ++i) {
      if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) {
        peak = i;
        break;
      }
    }

    for (int i = 0; i < peak; ++i) {
      if (arr[i] >= arr[i + 1]) {
        return false;
      }
    }

    for (int i = peak + 1; i < arr_size; ++i) {
      if (arr[i - 1] <= arr[i]) {
        return false;
      }
    }

    return true;
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
  std::cout << std::boolalpha << solution.validMountainArray(arr) << std::endl;
  return 0;
}
