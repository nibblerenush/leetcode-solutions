#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    max_num = n;
    combination_size = k;
    
    vector<int> combination;
    vector<vector<int>> combinations;
    backtrack(combination, combinations);
    return move(combinations);
  }

private:
  void backtrack(vector<int>& combination, vector<vector<int>>& combinations) {
    if (static_cast<int>(combination.size()) == combination_size) {
      combinations.push_back(combination);
      return;
    }
    
    int init_num = !combination.empty() ? combination.back() + 1 : 1;
    for (int num = init_num; num <= max_num; ++num) {
      combination.push_back(num);
      backtrack(combination, combinations);
      combination.pop_back();
    }
  }

private:
  int max_num = 0;
  int combination_size = 0;
};

int main() {
  int n = 0, k = 0;
  std::cin >> n >> k;

  Solution solution;
  auto combinations = solution.combine(n, k);
  for (const auto& combination : combinations) {
    for (int num : combination) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
