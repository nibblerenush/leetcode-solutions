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
  int minCost(string colors, vector<int>& neededTime) {
    const int n = neededTime.size();
    int minTime = 0;
    
    int i = 0;
    while (i < n) {
      int j = i + 1;
      int sum = neededTime[i];
      int maxValue = neededTime[i];
      
      while (j < n) {
        if (colors[j] == colors[j - 1]) {
          sum += neededTime[j];
          maxValue = max(maxValue, neededTime[j]);
          ++j;
        }
        else {
          break;
        }
      }
      
      if (j - i > 1) {
        minTime += sum - maxValue;
      }
      
      i = j;
    }
    
    return minTime;
  }
};

int main() {
  return 0;
}
