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
  int singleNumber(vector<int>& nums) {
    unordered_set<int> hashset;
    int sum_of_nums = 0;
    int sum_of_hashset = 0;
    
    for (int num : nums) {
      if (!hashset.count(num)) {
        hashset.insert(num);
        sum_of_hashset += num;
      }
      sum_of_nums += num;
    }
    
    return 2 * sum_of_hashset - sum_of_nums;
  }
};

int main() {
  return 0;
}
