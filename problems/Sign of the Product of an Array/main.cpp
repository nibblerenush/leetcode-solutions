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
  int arraySign(vector<int>& nums)
  {
    int product = 1;
    for (int num : nums)
    {
      if (num < 0)
      {
        product *= -1;
      }
      else if (num == 0)
      {
        return 0;
      }
    }

    return signFunc(product);
  }

private:
  int signFunc(int x)
  {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
  }
};

int main() {
  return 0;
}
