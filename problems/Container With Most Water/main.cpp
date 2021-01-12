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
    int j = (int)height.size() - 1;
    int result = 0;
    
    while (i < j) {
      int area = min(height[i], height[j]) * (j - i);
      result = max(result, area);
      
      if (height[i] < height[j]) {
        i += 1;
      }
      else {
        j -= 1;
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
