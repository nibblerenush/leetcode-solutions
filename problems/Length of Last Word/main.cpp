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
  int lengthOfLastWord(string s) {
    const int n = s.length();
    
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        for (int j = i - 1; j >= 0; --j) {
          if (s[j] == ' ') {
            return i - j;
          }
        }
        return i + 1;
      }
    }
    
    return 0;
  }
};

int main() {
  return 0;
}
