#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool isBadVersion(int version) {
  return false;
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
  return 0;
}
