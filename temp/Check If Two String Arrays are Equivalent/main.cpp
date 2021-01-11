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
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int i = 0, j = 0;
    int k = 0, l = 0;

    while (i < (int)word1.size() && k < (int)word2.size()) {
      if (word1[i][j++] != word2[k][l++]) {
        return false;
      }

      if (j >= (int)word1[i].length()) {
        j = 0;
        i += 1;
      }

      if (l >= (int)word2[k].length()) {
        l = 0;
        k += 1;
      }
    }
    
    return i >= (int)word1.size() && k >= (int)word2.size();
  }
};

int main() {
  return 0;
}
