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
  int mySqrt(int x) {
    long long left = 0;
    long long right = x;

    long long middle = 0;
    long long result = 0;

    while (left <= right) {
      middle = left + (right - left) / 2;
      if (middle * middle > x) {
        right = middle - 1;
      }
      else if (middle * middle <= x) {
        left = middle + 1;
        result = left * left > x ? middle : result;
      }
    }

    return result;
  }
};

int main() {
  int x;
  cin >> x;

  Solution solution;
  cout << solution.mySqrt(x) << endl;
  return 0;
}
