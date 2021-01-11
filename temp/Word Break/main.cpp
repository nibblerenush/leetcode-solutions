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
  bool wordBreak(string s, vector<string>& wordDict) {
    move(wordDict.begin(), wordDict.end(), inserter(word_set, word_set.begin()));
    return backtrack(s, 0);
  }

private:
  bool backtrack(const string& s, int begin) {
    if (begin >= (int)s.length()) {
      return true;
    }
    
    if (memorization.count(begin)) {
      return false;
    }
    
    for (int i = begin; i < (int)s.length(); ++i) {
      string substr = s.substr(begin, i - begin + 1);
      if (word_set.count(substr) && backtrack(s, i + 1)) {
        return true;
      }
    }
    
    memorization.insert(begin);
    return false;
  }

private:
  unordered_set<string> word_set;
  unordered_set<int> memorization;
};

int main() {
  return 0;
}
