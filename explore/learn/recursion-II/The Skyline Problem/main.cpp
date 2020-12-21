#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    size = buildings.size();
    return divide_and_conquer(0, buildings.size() - 1, buildings);
  }

private:
  vector<vector<int>> divide_and_conquer(int start, int end, const vector<vector<int>>& buildings) {
    if (start >= 0 && start < size && end >= 0 && end < size && start <= end) {
      vector<vector<int>> skyline;
      if (start == end) {
        skyline.push_back({ buildings[start][LEFT_INDEX], buildings[start][HEIGHT_INDEX] });
        skyline.push_back({ buildings[start][RIGHT_INDEX], 0 });
        return skyline;
      }

      int mid = (start + end) / 2;
      auto left_skyline = divide_and_conquer(start, mid, buildings);
      auto right_skyline = divide_and_conquer(mid + 1, end, buildings);
      
      int i = 0;
      int j = 0;
      int left_size = left_skyline.size();
      int right_size = right_skyline.size();
      int left_y = 0;
      int right_y = 0;

      while (i < left_size && j < right_size) {
        int left_x = left_skyline[i][X_INDEX];
        int right_x = right_skyline[j][X_INDEX];
        int x = 0;
        
        if (left_x < right_x) {
          left_y = left_skyline[i++][Y_INDEX];
          x = left_x;
        }
        else if (right_x < left_x) {
          right_y = right_skyline[j++][Y_INDEX];
          x = right_x;
        }
        else {
          x = left_x;
          left_y = left_skyline[i++][Y_INDEX];
          right_y = right_skyline[j++][Y_INDEX];
        }

        int y = max(left_y, right_y);
        if (skyline.empty() || y != skyline.back()[Y_INDEX]) {
          skyline.push_back({ x, y });
        }
      }

      while (i < left_size) {
        int left_x = left_skyline[i][X_INDEX];
        left_y = left_skyline[i++][Y_INDEX];
        int y = max(left_y, right_y);
        if (skyline.empty() || y != skyline.back()[Y_INDEX]) {
          skyline.push_back({ left_x, y });
        }
      }

      while (j < right_size) {
        int right_x = right_skyline[j][X_INDEX];
        right_y = right_skyline[j++][Y_INDEX];
        int y = max(left_y, right_y);
        if (skyline.empty() || y != skyline.back()[Y_INDEX]) {
          skyline.push_back({ right_x, y });
        }
      }
      return skyline;
    }
    return {};
  }

private:
  int size = 0;

  const int LEFT_INDEX = 0;
  const int RIGHT_INDEX = 1;
  const int HEIGHT_INDEX = 2;

  const int X_INDEX = 0;
  const int Y_INDEX = 1;
};

int main() {
  vector<vector<int>> buildings = {
    {2, 9, 10},
    {3, 7, 15},
    {5, 12, 12},
    {15, 20, 10},
    {19, 24, 8}
  };

  Solution solution;
  auto skyline = solution.getSkyline(buildings);
  for (const auto& point : skyline) {
    cout << "x = " << point[0] << " y = " << point[1] << '\n';
  }
  return 0;
}
