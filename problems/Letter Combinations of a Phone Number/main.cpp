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
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    size = digits.size();

    vector<string> result;
    backtrack(digits, 0, result);
    return result;
  }

private:
  void backtrack(const string& digits, int idx, vector<string>& combinations) {
    if (static_cast<int>(combination.size()) == size) {
      combinations.push_back(combination);
      return;
    }

    for (char letter : num_letters.at(digits[idx])) {
      combination.push_back(letter);
      backtrack(digits, idx + 1, combinations);
      combination.pop_back();
    }
  }

private:
  const unordered_map<char, string> num_letters {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
  };

  int size = 0;
  string combination;
};

int main() {
  return 0;
}
