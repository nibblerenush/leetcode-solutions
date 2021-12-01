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
  bool isPowerOfThree(int n)
  {
    if (n <= 0)
    {
      return false;
    }

    while (n > 1)
    {
      if (n % 3 != 0)
      {
        return false;
      }

      n /= 3;
    }

    return true;
  }
};

int main() {
  return 0;
}
