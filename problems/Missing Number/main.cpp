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

class Solution
{
public:
  int missingNumber(vector<int>& nums)
  {
    const int n = nums.size();

    int sum_of_nums = 0;
    for (int i = 0; i <= n; ++i)
    {
      sum_of_nums += i;
    }

    for (int num : nums)
    {
      sum_of_nums -= num;
    }

    return sum_of_nums;
  }
};

int main() {
  return 0;
}
