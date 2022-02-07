#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    
    // Form the m_num_count
    for (int num : nums) {
      ++m_num_count[num];
    }

    // Form the m_permutation_size
    m_permutation_size = nums.size();
    
    vector<int> permutation;
    backtrack(permutation, result);
    return result;
  }

private:
  void backtrack(vector<int>& permutation, vector<vector<int>>& permutations) {
    if (permutation.size() == m_permutation_size) {
      permutations.push_back(permutation);
      return;
    }
    
    for (auto& num_count : m_num_count) {
      if (num_count.second != 0) {
        permutation.push_back(num_count.first);
        --num_count.second;
        
        backtrack(permutation, permutations);
        
        permutation.pop_back();
        ++num_count.second;
      }
    }
  }

private:
  unordered_map<int, int> m_num_count;
  size_t m_permutation_size = 0;
};

int main() {
  return 0;
}
