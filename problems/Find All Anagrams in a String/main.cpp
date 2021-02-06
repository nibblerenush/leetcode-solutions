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
  vector<int> findAnagrams(string s, string p) {
    // size_t to int
    const int s_len = s.length();
    const int p_len = p.length();
    
    // init result
    vector<int> result;
    
    // preprocessing
    unordered_map<char, int> symbol_count;
    for (char c : p) {
      symbol_count[c] -= 1;
    }
    
    int i = 0;
    int j = 0;
    
    while (j < s_len) {
      symbol_count[s[j]] += 1;
      if (symbol_count[s[j]] == 0) {
        symbol_count.erase(s[j]);
      }
      
      if (j - i == p_len) {
        symbol_count[s[i]] -= 1;
        if (symbol_count[s[i]] == 0) {
          symbol_count.erase(s[i]);
        }
        i += 1;
      }
      
      if (symbol_count.empty()) {
        result.push_back(i);
      }
      
      j += 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
