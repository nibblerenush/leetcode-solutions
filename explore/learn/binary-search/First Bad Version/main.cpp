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

int bad;

bool isBadVersion(int version) {
  return version >= bad;
}

class Solution {
public:
  int firstBadVersion(int n) {
    long int left = 1;
    long int right = static_cast<long int>(n) + 1;
    
    while (left < right) {
      long int mid = left + (right - left) / 2;
      if (check_version(mid)) {
        return mid + 1;
      }
      else if (!isBadVersion(mid)) {
        left = mid + 1;
      }
      else {
        right = mid;
      }
    }

    if (left != n + 1 && isBadVersion(left)) {
      return left;
    }
    return -1;
  }

private:
  bool check_version(int version) {
    return !isBadVersion(version) && isBadVersion(version + 1);
  }
};

int main() {
  int n;
  cin >> n >> bad;

  Solution solution;
  cout << solution.firstBadVersion(n) << endl;
  return 0;
}
