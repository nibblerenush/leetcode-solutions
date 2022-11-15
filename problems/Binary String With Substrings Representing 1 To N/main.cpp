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

class Solution {
public:
  bool queryString(string s, int n) {
    for (int num = 1; num <= n; ++num) {
      string binForm = getBin(num);
      if (s.find(binForm) == string::npos) {
        return false;
      }
    }
    return true;
  }

private:
  string getBin(int num) {
    string result;
    while (num) {
      if (num & 1) {
        result.push_back('1');
      }
      else {
        result.push_back('0');
      }
      num >>= 1;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  return 0;
}
