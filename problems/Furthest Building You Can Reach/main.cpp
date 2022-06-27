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
  int furthestBuilding(vector<int>& heights, int bricks, int ladders)
  {
    const int heightsSize = heights.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 1; i < heightsSize; ++i)
    {
      int diff = heights[i] - heights[i - 1];
      if (diff > 0)
      {
        pq.push(diff);
      }

      if (pq.size() > ladders)
      {
        bricks -= pq.top();
        pq.pop();
      }

      if (bricks < 0)
      {
        return i - 1;
      }
    }
    
    return heights.size() - 1;
  }
};

int main()
{
  return 0;
}
