#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    std::unordered_set<std::string> deadends_set(deadends.begin(), deadends.end());
    
    std::queue<std::pair<std::string, int>> work_queue;
    if (!deadends_set.count("0000")) {
      work_queue.push({ "0000", 0 });
    }
    
    std::unordered_set<std::string> visited;
    visited.insert("0000");
    
    while (!work_queue.empty()) {
      std::string cur_comb = work_queue.front().first;
      int cur_level = work_queue.front().second;
      work_queue.pop();
      
      if (cur_comb == target) {
        return cur_level;
      }
      
      auto next_combs = getNextCombs(cur_comb);
      for (const auto& next_comb : next_combs) {
        if (!visited.count(next_comb) && !deadends_set.count(next_comb)) {
          work_queue.push({ next_comb, cur_level + 1 });
          visited.insert(next_comb);
        }
      }
    }

    return -1;
  }

private:
  std::vector<std::string> getNextCombs(const std::string& cur_comb) {
    std::vector<std::string> result;
    for (std::size_t i = 0; i < cur_comb.size(); ++i) {
      std::string next_comb = cur_comb;
      if (cur_comb[i] == '0') {
        next_comb[i] = '1';
        result.push_back(next_comb);
        next_comb[i] = '9';
        result.push_back(next_comb);
      }
      else if (cur_comb[i] == '9') {
        next_comb[i] = '0';
        result.push_back(next_comb);
        next_comb[i] = '8';
        result.push_back(next_comb);
      }
      else {
        next_comb[i] = cur_comb[i] + 1;
        result.push_back(next_comb);
        next_comb[i] = cur_comb[i] - 1;
        result.push_back(next_comb);
      }
    }
    return result;
  }
};

int main() {
  std::string target;
  std::cin >> target;

  int n = 0;
  std::cin >> n;
  std::vector<std::string> deadends(n);
  for (auto& deadend : deadends) {
    std::cin >> deadend;
  }

  Solution solution;
  std::cout << solution.openLock(deadends, target) << std::endl;
  return 0;
}
