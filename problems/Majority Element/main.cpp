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

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> num_count;

    for (int num : nums) {
      num_count[num] += 1;
      if (num_count[num] > size / 2) {
        return num;
      }
    }

    return 0;
  }
};

int main() {
  return 0;
}
