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
  string minWindow(string s, string t) {
    unordered_map<char, int> char_count;
    for (char c : t) {
      char_count[c]++;
    }
    
    int begin = 0, end = 0, head = 0;
    int distance = numeric_limits<int>::max();
    int counter = t.size();
    
    while (end < static_cast<int>(s.size())) {
      if (char_count[s[end]] > 0) {
        counter--;
      }
      
      char_count[s[end]]--;
      end++;
      
      while (counter == 0) {
        if (end - begin < distance) {
          distance = end - begin;
          head = begin;
        }

        if (char_count[s[begin]] == 0) {
          counter++;
        }
        char_count[s[begin]]++;
        begin++;
      }
    }
    
    return distance == numeric_limits<int>::max() ? "" : s.substr(head, distance);
  }
};

int main() {
  return 0;
}
