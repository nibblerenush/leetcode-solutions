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
  bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int, pair<int, int>> num_rowcol;
    unordered_set<int> used_rows;

    for (int i = 0; i < int(pieces.size()); ++i) {
      for (int j = 0; j < int(pieces[i].size()); ++j) {
        num_rowcol[pieces[i][j]] = { i, j };
      }
    }
    
    int cur_row = -1;
    int cur_col = -1;

    for (int num : arr) {
      if (!num_rowcol.count(num)) {
        return false;
      }

      int row = num_rowcol[num].first;
      int col = num_rowcol[num].second;

      if (row != cur_row) {
        if (used_rows.count(row)) {
          return false;
        }
        else {
          used_rows.insert(row);
          cur_row = row;
        }
      }
      else if (col - cur_col != 1) {
        return false;
      }
      cur_col = col;
    }

    return true;
  }
};

int main() {
  return 0;
}
