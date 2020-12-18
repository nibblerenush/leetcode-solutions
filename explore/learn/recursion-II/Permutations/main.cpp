#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    size = nums.size();

    vector<vector<int>> permutations;
    backtrack(nums, permutations);
    return permutations;
  }

private:
  void backtrack(const vector<int>& nums, vector<vector<int>>& permutations) {
    if (static_cast<int>(permutation.size()) == size) {
      permutations.push_back(permutation);
      return;
    }
    
    for (int num : nums) {
      if (!used_nums.count(num)) {
        place_num(num);
        backtrack(nums, permutations);
        remove_num(num);
      }
    }
  }

private:
  void place_num(int num) {
    permutation.push_back(num);
    used_nums.insert(num);
  }

  void remove_num(int num) {
    permutation.pop_back();
    used_nums.erase(num);
  }

private:
  int size = 0;
  vector<int> permutation;
  unordered_set<int> used_nums;
};

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  auto permutations = solution.permute(nums);
  for (const auto& permutation : permutations) {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  }
  return 0;
}
