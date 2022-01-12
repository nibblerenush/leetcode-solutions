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

class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
  {
    // for finding loop
    vector<bool> visited(numCourses, false);
    // for memorization
    vector<bool> used(numCourses, false);
    // adj matrix
    vector<vector<int>> adj(numCourses, vector<int>());
    // result
    vector<int> order;

    for (const auto& edge : prerequisites)
    {
      adj[edge[0]].push_back(edge[1]);
    }

    for (int v = 0; v < numCourses; ++v)
    {
      if (!dfs(v, adj, visited, used, order))
      {
        return {};
      }
    }

    return order;
  }

private:
  bool dfs(
    int v,
    const vector<vector<int>>& adj,
    vector<bool>& visited,
    vector<bool>& used,
    vector<int>& order)
  {
    if (visited[v])
    {
      return false;
    }

    if (used[v])
    {
      return true;
    }

    visited[v] = true;

    for (int w : adj[v])
    {
      if (!dfs(w, adj, visited, used, order))
      {
        return false;
      }
    }

    visited[v] = false;

    used[v] = true;

    order.push_back(v);

    return true;
  }
};

int main() {
  return 0;
}
