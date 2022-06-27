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
  int largestPerimeter(vector<int>& nums)
  {
    const int numsSize = nums.size();
    sort(nums.begin(), nums.end());

    int perimeter = 0;
    for (int i = numsSize - 1; i >= 2; --i)
    {
      if (IsTriangle(nums[i], nums[i - 1], nums[i - 2]))
      {
        perimeter = nums[i] + nums[i - 1] + nums[i - 2];
        break;
      }
    }

    return perimeter;
  }

private:
  bool IsTriangle(int a, int b, int c)
  {
    return a + b > c && a + c > b && b + c > a;
  }
};

int main() {
  return 0;
}
