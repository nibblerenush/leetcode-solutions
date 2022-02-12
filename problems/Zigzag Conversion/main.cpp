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
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    
    string result;
    const int maxStep = (numRows - 1) * 2;
    const int len = s.length();
    
    for (int i = 0; i < numRows; ++i) {
      int j = i;
      if (j < len) {
        result.push_back(s[j]);
      }
      else {
        break;
      }
      
      int step2 = j * 2;
      int step1 = maxStep - step2;
      
      while (true) {
        if (step1 != 0) {
          j += step1;
          if (j < len) {
            result.push_back(s[j]);
          }
          else {
            break;
          }
        }
        
        if (step2 != 0) {
          j += step2;
          if (j < len) {
            result.push_back(s[j]);
          }
          else {
            break;
          }
        }
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
