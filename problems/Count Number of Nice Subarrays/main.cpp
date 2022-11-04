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
  int numberOfSubarrays(vector<int>& nums, int k) {
    const int size = static_cast<int>(nums.size());

    vector<int> indexes;
    indexes.push_back(-1);
    for (int i = 0; i < size; ++i) {
      if (nums[i] % 2 != 0) {
        indexes.push_back(i);
      }
    }
    indexes.push_back(size);

    int i = 1;
    int j = i + k - 1;
    int indexesSize = static_cast<int>(indexes.size());
    int result = 0;
    while (j < indexesSize - 1) {
      int curNum = (indexes[i] - indexes[i - 1]) * (indexes[j + 1] - indexes[j]);
      result += curNum;
      ++i;
      ++j;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
