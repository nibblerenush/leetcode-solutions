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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    int prev_size = 0;

    for (int i = 0; i < numRows; ++i) {
      result.push_back(vector<int>{1});

      for (int j = 1; j <= prev_size; ++j) {
        if (j == prev_size) {
          result[i].push_back(1);
        }
        else {
          result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
      }
      prev_size++;
    }

    return result;
  }
};

int main() {
  return 0;
}
