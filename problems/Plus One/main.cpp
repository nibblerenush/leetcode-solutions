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
  vector<int> plusOne(vector<int>& digits) {
    vector<int> result;

    int temp = 1;
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
      if (digits[i] + temp == 10) {
        result.push_back(0);
        if (i == 0) {
          result.push_back(1);
        }
      }
      else {
        result.push_back(digits[i] + temp);
        temp = 0;
      }
    }
    
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  return 0;
}
