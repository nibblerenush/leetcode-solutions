#include <iostream>
#include <vector>

class Solution {
public:
  void helper(std::vector<std::vector<int>>& image, std::vector<std::vector<bool>>& visited, int sr, int sc, int newColor, int oldColor) {
    int rowSize = image.size();
    int colSize = image[0].size();

    if (sr >= 0 && sr < rowSize && sc >= 0 && sc < colSize && image[sr][sc] == oldColor && !visited[sr][sc]) {
      image[sr][sc] = newColor;
      visited[sr][sc] = true;
      helper(image, visited, sr + 1, sc, newColor, oldColor);
      helper(image, visited, sr - 1, sc, newColor, oldColor);
      helper(image, visited, sr, sc + 1, newColor, oldColor);
      helper(image, visited, sr, sc - 1, newColor, oldColor);
    }
  }

  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    std::vector<std::vector<bool>> visited(image.size(), std::vector<bool>(image[0].size(), false));
    helper(image, visited, sr, sc, newColor, oldColor);
    return image;
  }
};

int main() {
  int sr = 0, sc = 0, newColor = 0;
  std::cin >> sr >> sc >> newColor;

  int m = 0, n = 0;
  std::cin >> m >> n;

  std::vector<std::vector<int>> image(m, std::vector<int>(n, 0));
  for (auto& row : image) {
    for (auto& cell : row) {
      std::cin >> cell;
    }
  }

  Solution solution;
  auto result = solution.floodFill(image, sr, sc, newColor);
  for (const auto& row : result) {
    for (const auto& cell : row) {
      std::cout << cell << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}
