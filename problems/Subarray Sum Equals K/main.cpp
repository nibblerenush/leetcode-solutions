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
  int subarraySum(vector<int>& nums, int k) {
    // prepare
    int result = 0;
    int prefixsum = 0;
    unordered_map<int, int> prefixsum_count;
    prefixsum_count[prefixsum] += 1;
    
    // sum(i, j) = sum(0, j) - sum(0, i), where
    // sum(i, j) - the sum of all the elements from index i to j - 1;
    // in our case sum(i, j) = k =>
    // k = sum(0, j) - sum(0, i) =>
    // sum(0, i) = sum(0, j) - k
    
    for (int num : nums) {
      prefixsum += num;
      if (prefixsum_count.count(prefixsum - k)) {
        result += prefixsum_count[prefixsum - k];
      }
      prefixsum_count[prefixsum] += 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
