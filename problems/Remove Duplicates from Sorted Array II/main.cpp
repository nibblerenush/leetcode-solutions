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
  int removeDuplicates(vector<int>& nums) {
    size_t j = 0;
    size_t count = 1;

    for (size_t i = 1; i < nums.size(); ++i)
    {
      if (nums[i] == nums[i - 1])
      {
        ++count;

        if (count > 2 && j == 0)
        {
          j = i; // new place for insert
        }
      }
      else
      {
        count = 1;
      }

      if (count <= 2 && j != 0)
      {
        nums[j++] = nums[i];
      }
    }

    return j != 0 ? static_cast<int>(j) : nums.size();
  }
};

int main() {
  return 0;
}
