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
  vector<string> generateParenthesis(int n) {
    max_size = n;
    vector<string> result;
    backtrack("", 0, 0, result);
    return result;
  }

private:
  void backtrack(string parenthese, int open, int closed, vector<string>& parentheses) {
    if (open + closed == 2 * max_size) {
      parentheses.push_back(move(parenthese));
      return;
    }

    if (open < max_size) {
      backtrack(parenthese + '(', open + 1, closed, parentheses);
    }

    if (closed < open) {
      backtrack(parenthese + ')', open, closed + 1, parentheses);
    }
  }

private:
  int max_size = 0;
};

int main() {
  return 0;
}
