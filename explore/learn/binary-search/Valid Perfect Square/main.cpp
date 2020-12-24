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
  bool isPerfectSquare(int num) {
    int sqrt_from_num = mySqrt(num);
    return sqrt_from_num * sqrt_from_num == num;
  }

private:
  int mySqrt(int x) {
    long long left = 0;
    long long right = x;
    
    while (left + 1 < right) {
      long long mid = left + (right - left) / 2;
      
      if (mid * mid == x) {
        return mid;
      }
      else if (mid * mid < x) {
        left = mid;
      }
      else {
        right = mid;
      }
    }
    
    if (right * right <= x) {
      return right;
    }
    
    if (left * left <= x) {
      return left;
    }
    
    return -1;
  }
};

int main() {
  int num;
  cin >> num;

  Solution solution;
  cout << boolalpha << solution.isPerfectSquare(num) << endl;
  return 0;
}
