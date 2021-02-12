#include <algorithm>
#include <cmath>
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
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> num_group;
    unordered_map<int, vector<int>> group_nums;
    
    for (int num : nums) {
      num_group[num] = num;
    }
    
    for (const auto& item : num_group) {
      int num = item.first;
      int group = item.second;
      group_nums[group].push_back(num);
    }
    
    for (const auto& item : num_group) {
      int num = item.first;
      int group = item.second;
      
      if (num_group.count(num - 1)) {
        int old_group = num_group[num - 1];
        for (int num : group_nums[old_group]) {
          group_nums[group].push_back(num);
          num_group[num] = group;
        }
      }
    }
    
    int result = 0;
    for (const auto& item : group_nums) {
      result = max(result, (int)item.second.size());
    }
    
    return result;
  }
};

int main() {
  return 0;
}
