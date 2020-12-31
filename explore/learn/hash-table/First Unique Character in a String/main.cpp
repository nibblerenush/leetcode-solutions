#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int size = s.size();
    unordered_map<char, int> char_count;

    for (char c : s) {
      ++char_count[c];
    }

    for (int i = 0; i < size; ++i) {
      if (char_count[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  string s;
  cin >> s;

  Solution solution;
  cout << solution.firstUniqChar(s) << endl;
  return 0;
}
