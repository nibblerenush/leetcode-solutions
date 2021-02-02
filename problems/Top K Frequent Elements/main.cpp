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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    unordered_map<int, int> num_count;
    unordered_map<int, vector<int>> count_num;
    
    for (int num : nums) {
      ++num_count[num];
    }
    
    for (const auto& item : num_count) {
      count_num[item.second].push_back(item.first);
    }
    
    int max_count = max_element(count_num.begin(), count_num.end())->first;
    
    for (int cur_count = max_count; cur_count >= 1; --cur_count) {
      if (count_num.count(cur_count)) {
        for (int num : count_num[cur_count]) {
          result.push_back(num);
          if ((int)result.size() == k) {
            return result;
          }
        }
      }
    }
    
    return {};
  }
};

int main() {
  return 0;
}
