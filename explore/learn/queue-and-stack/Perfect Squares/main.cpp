#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  int numSquares(int n) {
    int result = std::numeric_limits<int>::max();
    
    std::queue<std::pair<int, int>> work_queue;
    work_queue.push({ n, 0 });
    
    std::vector<bool> visited(n + 1, false);
    visited[n] = true;
    
    while (!work_queue.empty()) {
      int remain = work_queue.front().first;
      int step = work_queue.front().second;
      work_queue.pop();
      
      if (remain == 0) {
        result = std::min(result, step);
      }
      
      for (int i = 1; i * i <= remain; ++i) {
        int new_remain = remain - i * i;
        if (!visited[new_remain]) {
          work_queue.push({ new_remain, step + 1 });
          visited[new_remain] = true;
        }
      }
    }
    
    return result;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  Solution solution;
  std::cout << solution.numSquares(n) << std::endl;
  return 0;
}
