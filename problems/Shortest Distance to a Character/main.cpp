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
  vector<int> shortestToChar(string s, char c) {
    // size_t to int
    const int length = s.length();
    
    // init result
    vector<int> result;
    
    int begin = -10'000;
    int end = 0;
    
    while (end < length) {
      if (s[end] == c) {
        int i = begin >= 0 ? begin + 1 : 0;
        
        while (i <= end) {
          result.push_back(min(i - begin, end - i));
          i += 1;
        }
        
        begin = end;
      }
      
      end += 1;
    }
    
    // post processing
    int i = begin + 1;
    while (i < length) {
      result.push_back(i - begin);
      i += 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
