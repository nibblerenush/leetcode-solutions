#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  vector<string> letterCasePermutation(string s) {
    vector<string> permutations;
    Backtrack(s, 0, permutations);
    return permutations;
  }

private:
  void Backtrack(string s, int index, vector<string>& permutations)
  {
    permutations.push_back(s);
    const int sLen = s.length();
    
    for (int i = index; i < sLen; ++i)
    {
      char& c = s[i];
      if (isalpha(c))
      {
        if (c == tolower(c))
        {
          c = toupper(c);
          Backtrack(s, i + 1, permutations);
          c = tolower(c);
        }
        else
        {
          c = tolower(c);
          Backtrack(s, i + 1, permutations);
          c = toupper(c);
        }
      }
    }
  }
};

int main() {
  return 0;
}
