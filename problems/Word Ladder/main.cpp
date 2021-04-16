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
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<int, string>> work_queue;
    work_queue.push({ 1, move(beginWord) });
    
    while (!work_queue.empty()) {
      int cur_level = work_queue.front().first;
      string cur_word = move(work_queue.front().second);
      work_queue.pop();
      
      if (cur_word == endWord) {
        return cur_level;
      }
      
      for (auto& word : wordList) {
        if (is_diff_one_elem(cur_word, word)) {
          work_queue.push({ cur_level + 1, move(word) });
        }
      }
    }
    
    return 0;
  }

private:
  bool is_diff_one_elem(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
      return false;
    }
    
    int diff_count = 0;
    for (int i = 0; i < (int)s1.length(); ++i) {
      if (s1[i] != s2[i]) {
        ++diff_count;
      }
    }
    
    return diff_count == 1;
  }
};

int main() {
  return 0;
}
