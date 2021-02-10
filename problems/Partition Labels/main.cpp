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
  vector<int> partitionLabels(string S) {
    // size_t to int
    const int length = S.length();
    
    // init result
    vector<int> result;
    
    // prepare
    unordered_map<char, int> char_last_idx;
    for (int i = 0; i < length; ++i) {
      char_last_idx[S[i]] = i;
    }

    // algorithm
    int i = 0;
    int j = 0;
    while (j < length) {
      int start = i;
      
      while (i <= j) {
        if (char_last_idx[S[i]] > j) {
          j = char_last_idx[S[i]];
        }
        i += 1;
      }
      
      j += 1;
      result.push_back(j - start);
    }
    
    return result;
  }
};

int main() {
  return 0;
}
