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
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hashset;
    for (const auto& num : nums) {
      if (hashset.count(num)) {
        return true;
      }
      hashset.insert(num);
    }
    return false;
  }
};

int main() {
  return 0;
}
