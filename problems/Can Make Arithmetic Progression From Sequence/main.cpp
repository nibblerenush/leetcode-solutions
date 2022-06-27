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
  bool canMakeArithmeticProgression(vector<int>& arr)
  {
    const int arrSize = arr.size();
    sort(arr.begin(), arr.end());

    const int diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; ++i)
    {
      int newDiff = arr[i] - arr[i - 1];
      if (newDiff != diff)
      {
        return false;
      }
    }

    return true;
  }
};

int main() {
  return 0;
}
