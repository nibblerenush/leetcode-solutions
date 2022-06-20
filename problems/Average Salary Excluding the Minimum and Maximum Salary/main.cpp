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
  double average(vector<int>& salary)
  {
    int maxSalary = numeric_limits<int>::min();
    int minSalary = numeric_limits<int>::max();
    int sum = 0;

    for (int i = 0; i < (int)salary.size(); ++i)
    {
      sum += salary[i];
      if (salary[i] > maxSalary)
      {
        maxSalary = salary[i];
      }
      if (salary[i] < minSalary)
      {
        minSalary = salary[i];
      }
    }

    return (sum - maxSalary - minSalary) / (salary.size() - 2.);
  }
};

int main() {
  return 0;
}
