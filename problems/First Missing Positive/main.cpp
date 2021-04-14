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
  int firstMissingPositive(vector<int>& nums) {
    nums.push_back(0);
    int N = static_cast<int>(nums.size());
    
    for_each(nums.begin(), nums.end(), [N](int& num) {
      if (num < 0 || num >= N) {
        num = 0;
      }
    });
    
    for (int i = 0; i < N; ++i) {
      nums[nums[i] % N] += N;
    }
    
    for (int i = 1; i < N; ++i) {
      if (nums[i] / N == 0) {
        return i;
      }
    }
    
    return N;
  }
};

int main() {
  return 0;
}
