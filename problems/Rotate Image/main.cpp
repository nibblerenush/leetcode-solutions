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
  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    top = 0;
    bottom = size - 1;
    left = 0;
    right = size - 1;
    
    while (top <= bottom && left <= right) {
      for (int i = 0; i < size - 1; ++i) {
        rotate_right(matrix);
      }
      top += 1;
      bottom -= 1;
      left += 1;
      right -= 1;
      size = bottom - top + 1;
    }
  }

private:
  void rotate_right(vector<vector<int>>& matrix) {
    int i = top;
    int j = left;
    int temp = matrix[top][left];
    int direction = 0;
    
    while (direction != 4) {
      switch (direction) {
      case 0:
        if (j + 1 <= right) {
          swap(matrix[i][j++ + 1], temp);
        }
        else {
          direction += 1;
        }
        break;
      case 1:
        if (i + 1 <= bottom) {
          swap(matrix[i++ + 1][j], temp);
        }
        else {
          direction += 1;
        }
        break;
      case 2:
        if (j - 1 >= left) {
          swap(matrix[i][j-- - 1], temp);
        }
        else {
          direction += 1;
        }
        break;
      case 3:
        if (i - 1 >= top) {
          swap(matrix[i-- - 1][j], temp);
        }
        else {
          direction += 1;
        }
        break;
      }
    }
  }

private:
  int top = 0;
  int bottom = 0;
  int left = 0;
  int right = 0;
};

int main() {
  return 0;
}
