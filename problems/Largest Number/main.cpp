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
  string largestNumber(vector<int>& nums) {
    string largest_number;

    while (!nums.empty()) {
      int max_num = nums[0];
      int max_index = 0;

      for (int i = 1; i < (int)nums.size(); ++i) {
        if (is_greater(nums[i], max_num)) {
          max_num = nums[i];
          max_index = i;
        }
      }
      
      largest_number += to_string(max_num);
      if (largest_number == "0") {
        break;
      }

      swap(nums[max_index], nums.back());
      nums.pop_back();
    }

    return largest_number;
  }

private:
  bool is_greater(int num, int max_num) {
    string str_num = to_string(num);
    string str_max_num = to_string(max_num);

    string x = str_num + str_max_num;
    string y = str_max_num + str_num;

    return x > y;
  }
};

int main() {
  return 0;
}
