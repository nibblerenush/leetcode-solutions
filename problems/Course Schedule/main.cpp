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
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    used.assign(numCourses, false);
    visited.assign(numCourses, false);
    
    vector<vector<int>> adj(numCourses, vector<int>());
    for (const auto& edge : prerequisites) {
      adj[edge[0]].push_back(edge[1]);
    }
    
    bool result = true;
    for (int i = 0; i < numCourses; ++i) {
      result = result && dfs(adj, i);
    }
    
    return result;
  }

private:
  bool dfs(const vector<vector<int>>& adj, int v) {
    if (used[v]) {
      return true;
    }
    
    if (visited[v]) {
      return false;
    }
    
    visited[v] = true;
    
    bool result = true;
    for (int w : adj[v]) {
      result = result && dfs(adj, w);
    }
    
    visited[v] = false;
    
    used[v] = true;
    return result;
  }

private:
  vector<bool> used;
  vector<bool> visited;
};

int main() {
  return 0;
}
