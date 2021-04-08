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
  int trap(vector<int>& height) {
    // Init
    int height_size = height.size();
    int i = 0;
    int j = height_size - 1;
    int result = 0;
    
    // Main algorithm
    while (i < j) {
      int min_height = min(height[i], height[j]);
      for (int k = i; k <= j; ++k) {
        if (height[k] < min_height) {
          result += min_height - height[k];
          height[k] = min_height;
        }
      }
      
      while (i < height_size && height[i] == min_height) {
        i += 1;
      }
      
      while (j >= 0 && height[j] == min_height) {
        j -= 1;
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
