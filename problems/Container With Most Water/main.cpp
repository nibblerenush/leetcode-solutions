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
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int result = numeric_limits<int>::min();

    while (i < j) {
      result = max(result, min(height[i], height[j]) * (j - i));

      if (height[i] < height[j]) {
        ++i;
      }
      else {
        --j;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
