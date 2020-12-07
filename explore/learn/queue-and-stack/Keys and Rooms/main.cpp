#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    int rooms_size = rooms.size();
    std::vector<int> visited(rooms_size, false);
    dfs(0, rooms, visited);
    return std::find(visited.begin(), visited.end(), false) == visited.end();
  }

private:
  void dfs(int v, const std::vector<std::vector<int>>& rooms, std::vector<int>& visited) {
    if (visited[v]) {
      return;
    }
    visited[v] = true;

    for (int w : rooms[v]) {
      dfs(w, rooms, visited);
    }
  }
};

int main() {
  std::vector<std::vector<int>> rooms;
  rooms.push_back(std::vector<int>{1});
  rooms.push_back(std::vector<int>{2});
  rooms.push_back(std::vector<int>{3});
  rooms.push_back(std::vector<int>{});

  Solution solution;
  std::cout << std::boolalpha << solution.canVisitAllRooms(rooms) << std::endl;
  return 0;
}
