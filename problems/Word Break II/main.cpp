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
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    m_word_dict_set.clear();
    move(wordDict.begin(), wordDict.end(), inserter(m_word_dict_set, m_word_dict_set.begin()));
    
    vector<string> result;
    vector<string> s_chunks;
    backtrack(s, 0, s_chunks, result);
    return result;
  }

private:
  void backtrack(const string& s, int begin, vector<string>& s_chunks, vector<string>& result) {
    const int length = s.length();
    
    if (begin >= length) {
      string s_with_spaces = accumulate(s_chunks.begin() + 1, s_chunks.end(), s_chunks[0], [](const string& big_str, const string& str) {
        return big_str + ' ' + str;
      });
      result.push_back(move(s_with_spaces));
    }
    
    for (int i = begin; i < length; ++i) {
      string substr = s.substr(begin, i - begin + 1);
      if (m_word_dict_set.count(substr)) {
        s_chunks.push_back(substr);
        backtrack(s, i + 1, s_chunks, result);
        s_chunks.pop_back();
      }
    }
  }

private:
  unordered_set<string> m_word_dict_set;
};

int main() {
  return 0;
}
