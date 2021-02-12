#include <algorithm>
#include <cmath>
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

class Solution {
public:
  int numberOfSteps(int num) {
    int result = 0;

    while (num) {
      result += 1;
      if (num % 2 == 0) {
        num /= 2;
      }
      else {
        num -= 1;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
