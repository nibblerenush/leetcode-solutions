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
  int numSquares(int n) {
    int result = 0;
    
    queue<pair<int, int>> work_queue;
    work_queue.push({ n, 0 });
    
    vector<bool> visited(n + 1, false);
    visited[n] = true;
    
    while (!work_queue.empty()) {
      int remain = work_queue.front().first;
      int step = work_queue.front().second;
      work_queue.pop();
      
      if (remain == 0) {
        result = step;
        break;
      }
      
      for (int i = 1; i * i <= remain; ++i) {
        int new_remain = remain - i * i;
        
        if (!visited[new_remain]) {
          work_queue.push({ new_remain, step + 1 });
          visited[new_remain] = true;
        }
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
