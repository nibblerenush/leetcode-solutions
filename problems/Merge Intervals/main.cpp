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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return {};
    }
    
    vector<vector<int>> result;
    
    sort(intervals.begin(), intervals.end());
    result.push_back(move(intervals[0]));
    
    for (int i = 1; i < (int)intervals.size(); ++i) {
      vector<int>& last = result.back();
      if (intervals[i][0] > last[1]) {
        result.push_back(move(intervals[i]));
      }
      else if (intervals[i][1] > last[1]) {
        last[1] = intervals[i][1];
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
