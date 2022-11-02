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
  string addBinary(string a, string b) {
    string result;
    int a_idx = a.length() - 1;
    int b_idx = b.length() - 1;
    int temp = 0;
    
    while (a_idx >= 0 && b_idx >= 0) {
      int a_bit = a[a_idx] - '0';
      int b_bit = b[b_idx] - '0';
      int r_bit = a_bit + b_bit + temp;

      switch (r_bit) {
      case 0:
        result.push_back('0');
        temp = 0;
        break;
      case 1:
        result.push_back('1');
        temp = 0;
        break;
      case 2:
        result.push_back('0');
        temp = 1;
        break;
      case 3:
        result.push_back('1');
        temp = 1;
        break;
      }

      a_idx--;
      b_idx--;
    }
    
    auto get_prefix = [&temp, &result](const string& s, int idx) {
      while (idx >= 0) {
        int s_bit = s[idx] - '0';
        int r_bit = s_bit + temp;

        switch (r_bit) {
        case 0:
          result.push_back('0');
          temp = 0;
          break;
        case 1:
          result.push_back('1');
          temp = 0;
          break;
        case 2:
          result.push_back('0');
          temp = 1;
          break;
        }

        idx--;
      }
    };

    get_prefix(a, a_idx);
    get_prefix(b, b_idx);
    if (temp == 1) {
      result.push_back('1');
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  return 0;
}
