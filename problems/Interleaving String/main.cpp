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
  bool isInterleave(string s1, string s2, string s3) {
    // Sum lengths of s1 and s2 must be equal to length of s3
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    
    // Sum of indexes 2D array "dynamic" equal to length of part s3
    // Value of 2D array "dynamic" is true if we can interleave this part of s3 
    vector<vector<bool>> dynamic(1 + s2.length(), vector<bool>(1 + s1.length(), false));
    dynamic[0][0] = true;

    // Fill first row
    for (int j = 1; j <= (int)s1.length(); ++j) {
      if (dynamic[0][j - 1]) {
        dynamic[0][j] = s1[j - 1] == s3[j - 1];
      }
      else {
        break;
      }
    }

    // Fill first column
    for (int i = 1; i <= (int)s2.length(); ++i) {
      if (dynamic[i - 1][0]) {
        dynamic[i][0] = s2[i - 1] == s3[i - 1];
      }
      else {
        break;
      }
    }

    for (int i = 1; i <= (int)s2.length(); ++i) {
      for (int j = 1; j <= (int)s1.length(); ++j) {
        // If prev. row is true
        if (dynamic[i - 1][j]) {
          dynamic[i][j] = s3[i + j - 1] == s2[i - 1];
        }

        // If prev. column is true
        if (dynamic[i][j - 1]) {
          dynamic[i][j] = s3[i + j - 1] == s1[j - 1];
        }
      }
    }
    
    return dynamic[s2.length()][s1.length()];
  }  
};

int main() {
  return 0;
}
