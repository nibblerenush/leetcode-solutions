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
  int countOdds(int low, int high)
  {
    int numCountsInInterval = high - low + 1;
    if (isEven(numCountsInInterval) || isEven(low))
    {
      return numCountsInInterval / 2;
    }
    
    return numCountsInInterval / 2 + 1;
  }

private:
  bool isEven(int num)
  {
    return num % 2 == 0;
  }
};

int main() {
  return 0;
}
