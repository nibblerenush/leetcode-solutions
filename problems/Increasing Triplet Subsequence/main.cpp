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
  bool increasingTriplet(vector<int>& nums) {
    // init
    int first_num = numeric_limits<int>::max();
    int second_num = numeric_limits<int>::max();

    // invariant for algorithm:
    // first_num < second_num < third_num
    
    for (int third_num : nums) {
      if (third_num < first_num) {
        first_num = third_num;
      }
      else if (first_num < third_num && third_num < second_num) {
        second_num = third_num;
      }
      else if (third_num > second_num) {
        return true;
      }
    }
    
    return false;
  }
};

int main() {
  return 0;
}
