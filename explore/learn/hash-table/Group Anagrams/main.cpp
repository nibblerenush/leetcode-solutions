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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashmap;
    for (const auto& str : strs) {
      auto sortedStr = str;
      sort(sortedStr.begin(), sortedStr.end());
      hashmap[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for_each(hashmap.begin(), hashmap.end(), [&result](const auto& item) {
      result.push_back(item.second);
    });

    return result;
  }
};

int main() {
  /*int n;
  cin >> n;

  vector<string> strs(n);
  for (auto& str : strs) {
    cin >> str;
  }*/

  vector<string> strs = {
    "eat", "tea", "tan", "ate", "nat", "bat"
  };

  Solution solution;
  for (const auto& row : solution.groupAnagrams(strs)) {
    for (const auto& str : row) {
      cout << str << ' ';
    }
    cout << '\n';
  }
  return 0;
}
