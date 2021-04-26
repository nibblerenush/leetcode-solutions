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
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> partitioning;
    backtrack(s, 0, partitioning, result);
    return result;
  }

private:
  void backtrack(const string& s, int index, vector<string>& partitioning, vector<vector<string>>& result) {
    int s_length = s.length();

    if (index >= s_length) {
      result.push_back(partitioning);
      return;
    }

    for (int i = index; i < s_length; ++i) {
      if (is_palindrome(s, index, i)) {
        partitioning.push_back(s.substr(index, i - index + 1));
        backtrack(s, i + 1, partitioning, result);
        partitioning.pop_back();
      }
    }
  }

  bool is_palindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  return 0;
}
