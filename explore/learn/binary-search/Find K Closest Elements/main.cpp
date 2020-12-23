#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    size = arr.size();
    vector<int> closest_elements(k);
    
    auto iter = lower_bound(arr.begin(), arr.end(), x);
    int i = distance(arr.begin(), iter);
    int j = i - 1;
    int count = 0;
    
    while (count != k) {
      int abs_i = i >= 0 && i < size ? abs(arr[i] - x) : numeric_limits<int>::max();
      int abs_j = j >= 0 && j < size ? abs(arr[j] - x) : numeric_limits<int>::max();
      if (abs_i < abs_j) { ++i; }
      else if (abs_j < abs_i) { --j; }
      else { arr[i] < arr[j] ? ++i : --j; }
      ++count;
    }
    
    int copy_begin = j >= 0 ? j + 1 : 0;
    copy(arr.begin() + copy_begin, arr.begin() + i, closest_elements.begin());
    return closest_elements;
  }

private:
  int size = 0;
};

int main() {
  int k, x, n;
  cin >> k >> x >> n;

  vector<int> arr(n);
  for (auto& num : arr) {
    cin >> num;
  }

  Solution solution;
  for (const auto& num : solution.findClosestElements(arr, k, x)) {
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}
