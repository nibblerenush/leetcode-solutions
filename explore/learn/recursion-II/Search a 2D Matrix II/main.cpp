#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return helper(0, matrix[0].size() - 1, matrix, target);
  }

private:
  bool helper(int row, int col, const vector<vector<int>>& matrix, int target) {
    if (row < static_cast<int>(matrix.size()) && col >= 0) {
      if (target == matrix[row][col]) {
        return true;
      }
      else if (target > matrix[row][col]) {
        return helper(row + 1, col, matrix, target);
      }
      else {
        return helper(row, col - 1, matrix, target);
      }
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {
    {1,4,7,11,15},
    {2,5,8,12,19},
    {3,6,9,16,22},
    {10,13,14,17,24},
    {18,21,23,26,30}
  };

  Solution solution;
  std::cout << std::boolalpha << solution.searchMatrix(matrix, 30) << std::endl;
  return 0;
}
