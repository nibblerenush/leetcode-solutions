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
  int nearestValidPoint(int x, int y, vector<vector<int>>& points)
  {
    int index = -1;
    const int pointsSize = points.size();
    int minManhattanDistance = numeric_limits<int>::max();
    
    for (int i = 0; i < pointsSize; ++i)
    {
      if (IsValid(x, y, points[i][0], points[i][1]))
      {
        int manhattanDistance = ManhattanDistance(x, y, points[i][0], points[i][1]);
        if (manhattanDistance < minManhattanDistance)
        {
          minManhattanDistance = manhattanDistance;
          index = i;
        }
      }
    }

    return index;
  }

private:
  int ManhattanDistance(int x1, int y1, int x2, int y2)
  {
    return abs(x1 - x2) + abs(y1 - y2);
  }

  bool IsValid(int x, int y, int a, int b)
  {
    return x == a || y == b;
  }
};

int main() {
  return 0;
}
