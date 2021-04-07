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
  int longestValidParentheses(string s) {
    set<int> index_set;
    stack<int> index_stack;
    
    for (int i = 0; i < int(s.length()); ++i) {
      if (s[i] == '(') {
        index_stack.push(i);
      }
      else if (!index_stack.empty()) {
        int index = index_stack.top();
        index_stack.pop();

        index_set.insert(index);
        index_set.insert(i);
      }
    }

    // Post processing
    if (index_set.empty()) {
      return 0;
    }
    
    int i = 0;
    int j = 0;
    int length = 0;
    vector<int> index_vector(index_set.begin(), index_set.end());
    
    for (j = 1; j < (int)index_vector.size(); ++j) {
      if (index_vector[j] - index_vector[j - 1] != 1) {
        length = max(length, j - i);
        i = j;
      }
    }
    
    length = max(length, j - i);
    return length;
  }
};

int main() {
  return 0;
}
