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
  int largestRectangleArea(vector<int>& heights) {
    size = heights.size();
    return divide_and_conquer(0, size - 1, heights);
  }

private:
  int divide_and_conquer(int start, int end, const vector<int>& heights) {
    if (start >= 0 && end >= 0 && start < size && end < size && start <= end) {
      int min_index = start;
      int min_height = heights[start];
      for (int i = start + 1; i <= end; ++i) {
        if (heights[i] < min_height) {
          min_index = i;
          min_height = heights[i];
        }
      }

      int rectangle_area = min_height * (end - start + 1);
      int left_rectangle_area = divide_and_conquer(start, min_index - 1, heights);
      int right_rectangle_area = divide_and_conquer(min_index + 1, end, heights);
      return max({ rectangle_area, left_rectangle_area, right_rectangle_area });
    }

    return 0;
  }

private:
  int size = 0;
};

int main() {
  return 0;
}
