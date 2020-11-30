#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int>& T) {
    int size_T = T.size();
    std::stack<std::pair<int, int>> sorted_tempers;
    std::vector<int> result(size_T);
    
    for (int i = size_T - 1; i >= 0; --i) {
      while (!sorted_tempers.empty() && T[i] >= sorted_tempers.top().first) {
        sorted_tempers.pop();
      }
      
      result[i] = sorted_tempers.empty() ? 0 : sorted_tempers.top().second - i;
      sorted_tempers.push({ T[i], i });
    }

    return result;
  }
};

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> T(n);
  for (auto& t : T) {
    std::cin >> t;
  }

  Solution solution;
  for (auto num : solution.dailyTemperatures(T)) {
    std::cout << num << ' ';
  }
  return 0;
}
