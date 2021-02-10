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
  vector<int> dailyTemperatures(vector<int>& T) {
    // size_t to int
    const int size = T.size();
    
    // prepare
    vector<int> result(size);
    stack<pair<int, int>> sorted_tempers;
    
    for (int i = size - 1; i >= 0; --i) {
      while (!sorted_tempers.empty() && T[i] >= sorted_tempers.top().first) {
        sorted_tempers.pop();
      }
      
      result[i] = sorted_tempers.empty() ? 0 : sorted_tempers.top().second - i;
      sorted_tempers.push({ T[i], i });
    }
    
    return result;
  }
};

int main() {
  return 0;
}
