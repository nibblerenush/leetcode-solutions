#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int countArrangement(int n) {
    max_size_of_array = n;
    max_num_in_array = n;

    int result = 0;
    backtrack(0, result);
    return result;
  }

private:
  void backtrack(int size_of_array, int& result) {
    if (size_of_array == max_size_of_array) {
      ++result;
      return;
    }
    
    for (int num = 1; num <= max_num_in_array; ++num) {
      int index = size_of_array + 1;
      if (!used_nums.count(num) && (num % index == 0 || index % num == 0)) {
        used_nums.insert(num);
        backtrack(size_of_array + 1, result);
        used_nums.erase(num);
      }
    }
  }

private:
  unordered_set<int> used_nums;
  int max_size_of_array;
  int max_num_in_array;
};

int main() {
  Solution solution;
  cout << solution.countArrangement(10) << endl;
  return 0;
}
