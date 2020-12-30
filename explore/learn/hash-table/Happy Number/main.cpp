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
  bool isHappy(int n) {
    unordered_set<int> hashset;
    
    while (true) {
      int digits_square_sum = get_digits_square_sum(n);
      if (digits_square_sum == 1) {
        return true;
      }
      if (hashset.count(digits_square_sum)) {
        return false;
      }
      hashset.insert(digits_square_sum);
      n = digits_square_sum;
    }
  }

private:
  int get_digits_square_sum(int n) {
    int result = 0;
    while (n != 0) {
      int temp = n % 10;
      result += temp * temp;
      n /= 10;
    }
    return result;
  }
};

int main() {
  int n;
  cin >> n;

  Solution solution;
  cout << boolalpha << solution.isHappy(n) << endl;
  return 0;
}
