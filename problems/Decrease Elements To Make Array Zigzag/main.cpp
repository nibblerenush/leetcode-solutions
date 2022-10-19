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
  int movesToMakeZigzag(vector<int>& nums) {
    return min(computeNumberOfMoves(nums, 0), computeNumberOfMoves(nums, 1));
  }

private:
  int computeNumberOfMoves(vector<int> nums, int beginIndex) {
    const int n = static_cast<int>(nums.size());
    int numberOfMoves = 0;
    
    for (int i = beginIndex; i < n; i += 2) {
      int leftVal = i - 1 >= 0 ? nums[i - 1] : numeric_limits<int>::max();
      int rightVal = i + 1 < n ? nums[i + 1] : numeric_limits<int>::max();
      if (nums[i] >= leftVal) {
        int moves = nums[i] - leftVal + 1;
        nums[i] -= moves;
        numberOfMoves += moves;
      }
      if (nums[i] >= rightVal) {
        int moves = nums[i] - rightVal + 1;
        nums[i] -= moves;
        numberOfMoves += moves;
      }
    }
    
    return numberOfMoves;
  }
};

int main() {
  return 0;
}
