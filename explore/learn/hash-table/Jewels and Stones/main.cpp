#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    int result = 0;
    unordered_set<char> jewels_hashset(jewels.begin(), jewels.end());
    
    for (char c : stones) {
      if (jewels_hashset.count(c)) {
        ++result;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
