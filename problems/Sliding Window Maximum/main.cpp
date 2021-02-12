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
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // size_t to int
    const int size = nums.size();
    
    // init
    vector<int> result;
    set<pair<int, int>, greater<pair<int, int>>> sliding_window;
    
    // algorithm
    int i = 0;
    int j = 0;
    while (j < size) {
      sliding_window.insert({ nums[j], j });
      if (j - i + 1 == k) {
        result.push_back(sliding_window.begin()->first);
        sliding_window.erase({ nums[i], i });
        i += 1;
      }
      j += 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
