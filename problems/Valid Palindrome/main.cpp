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
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    int s_length = s.length();
    
    while (i < j) {
      while (i < s_length && !isalnum(s[i])) {
        i += 1;
      }
      
      while (j >= 0 && !isalnum(s[j])) {
        j -= 1;
      }
      
      if (i < s_length && j >= 0 && tolower(s[i]) != tolower(s[j])) {
        return false;
      }
      
      i += 1;
      j -= 1;
    }
    
    return true;
  }
};

int main() {
  return 0;
}
