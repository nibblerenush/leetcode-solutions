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
  bool areAlmostEqual(string s1, string s2)
  {
    const int sLength = s1.length();
    
    vector<int> indexes;
    int indexCount = 0;

    for (int i = 0; i < sLength; ++i)
    {
      if (s1[i] != s2[i])
      {
        ++indexCount;
        indexes.push_back(i);
      }
    }

    if (indexCount == 0)
    {
      return true;
    }
    else if (indexCount == 2)
    {
      return s1[indexes[0]] == s2[indexes[1]] && s2[indexes[0]] == s1[indexes[1]];
    }

    return false;
  }
};

int main() {
  return 0;
}
