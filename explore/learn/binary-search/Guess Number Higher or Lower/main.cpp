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

int pick;

int guess(int num) {
  if (pick == num) {
    return 0;
  }
  else if (pick < num) {
    return -1;
  }
  else {
    return 1;
  }
}

class Solution {
public:
  int guessNumber(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (guess(mid) == 0) {
        return mid;
      }
      else if (guess(mid) == -1) {
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  int n;
  cin >> n >> pick;

  Solution solution;
  cout << solution.guessNumber(n) << endl;
  return 0;
}
