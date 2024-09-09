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
  int countDays(int days, vector<vector<int>>& meetings) {
    stack<vector<int>> withoutOverlaps;
    sort(meetings.begin(), meetings.end());
    for (const auto& item : meetings) {
      if (withoutOverlaps.empty()) {
        withoutOverlaps.push(item);
      }
      else {
        const auto top = withoutOverlaps.top();
        // overlap
        if (item[0] <= top[1]) {
          withoutOverlaps.pop();
          withoutOverlaps.push({ top[0], max(item[1], top[1]) });
        }
        else {
          withoutOverlaps.push(item);
        }
      }
    }
    
    int count = 0;
    if (!withoutOverlaps.empty()) {
      auto top = withoutOverlaps.top();
      withoutOverlaps.pop();
      
      count += days - top[1];
      while (!withoutOverlaps.empty()) {
        auto newTop = withoutOverlaps.top();
        withoutOverlaps.pop();
        count += top[0] - newTop[1] - 1;
        top = newTop;
      }
      count += top[0] - 1;
    }
    return count;
  }
};

int main() {
  return 0;
}
