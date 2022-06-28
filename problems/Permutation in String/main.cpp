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
  bool checkInclusion(string s1, string s2) {
    const int s1Length = s1.length();
    const int s2Length = s2.length();

    if (s1Length > s2Length) return false;
    
    int j = 0;
    unordered_map<char, int> stringDiff;
    for (; j < s1Length; ++j)
    {
      ++stringDiff[s2[j]];
      EraseIfZero(stringDiff, s2[j]);

      --stringDiff[s1[j]];
      EraseIfZero(stringDiff, s1[j]);
    }

    if (stringDiff.empty()) return true;
    
    for (int i = 0; j < s2Length; ++i, ++j)
    {
      --stringDiff[s2[i]];
      EraseIfZero(stringDiff, s2[i]);
      
      ++stringDiff[s2[j]];
      EraseIfZero(stringDiff, s2[j]);

      if (stringDiff.empty()) return true;
    }

    return false;
  }

private:
  void EraseIfZero(unordered_map<char, int>& stringDiff, char c)
  {
    if (stringDiff[c] == 0)
    {
      stringDiff.erase(c);
    }
  }
};

int main() {
  return 0;
}
