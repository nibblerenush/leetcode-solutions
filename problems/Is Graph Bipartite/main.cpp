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
  bool isBipartite(vector<vector<int>>& graph) {
    // prepare
    vector<int> distances(graph.size(), -1);
    
    // algorithm
    for (int i = 0; i < (int)graph.size(); ++i) {
      if (distances[i] == -1) {
        queue<int> work_queue;
        work_queue.push(i);
        distances[i] = 0;
        
        while (!work_queue.empty()) {
          int v = work_queue.front();
          work_queue.pop();
          
          for (int w : graph[v]) {
            if (distances[w] == -1) {
              work_queue.push(w);
              distances[w] = distances[v] + 1;
            }
            else if (abs(distances[w] - distances[v]) % 2 == 0) {
              return false;
            }
          }
        }
      }
    }
    
    return true;
  }
};

int main() {
  return 0;
}
