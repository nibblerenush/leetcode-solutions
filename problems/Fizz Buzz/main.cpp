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

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> result;
    for (int i = 1; i <= n; ++i)
    {
      if (i % 3 == 0 && i % 5 == 0)
      {
        result.push_back("FizzBuzz");
      }
      else if (i % 3 == 0)
      {
        result.push_back("Fizz");
      }
      else if (i % 5 == 0)
      {
        result.push_back("Buzz");
      }
      else
      {
        result.push_back(to_string(i));
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
