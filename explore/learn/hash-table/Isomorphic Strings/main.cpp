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
  bool isIsomorphic(string s, string t) {
    int size = s.size();
    unordered_map<char, char> hashmap_s_t;
    unordered_map<char, char> hashmap_t_s;
    
    for (int i = 0; i < size; ++i) {
      if (!hashmap_s_t.count(s[i]) && !hashmap_t_s.count(t[i])) {
        hashmap_s_t[s[i]] = t[i];
        hashmap_t_s[t[i]] = s[i];
      }
      else if (hashmap_s_t[s[i]] != t[i] || hashmap_t_s[t[i]] != s[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  string s, t;
  cin >> s >> t;

  Solution solution;
  cout << boolalpha << solution.isIsomorphic(s, t) << endl;
  return 0;
}
