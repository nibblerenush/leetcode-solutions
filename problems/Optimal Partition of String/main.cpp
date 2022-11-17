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
  int partitionString(string s) {
    unordered_set<char> usedChars;
    int result = 0;
    for (char c : s) {
      if (usedChars.count(c)) {
        ++result;
        usedChars.clear();
      }
      usedChars.insert(c);
    }

    // Post processing
    ++result;

    return result;
  }
};

int main() {
  return 0;
}
