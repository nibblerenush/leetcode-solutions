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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hashmap;
    for (const string& str : strs) {
      string sorted_str = str;
      sort(sorted_str.begin(), sorted_str.end());
      hashmap[move(sorted_str)].push_back(str);
    }
    
    vector<vector<string>> result;
    for_each(hashmap.begin(), hashmap.end(), [&result](const auto& item) {
      result.push_back(move(item.second));
    });
    return result;
  }
};

int main() {
  return 0;
}
