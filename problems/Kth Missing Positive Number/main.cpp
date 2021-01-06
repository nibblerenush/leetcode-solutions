#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int cur_num = 0;
    int miss_count = 0;
    
    int i = 0;
    while (i < (int)arr.size()) {
      ++cur_num;
      
      if (arr[i] == cur_num) {
        ++i;
      }
      else {
        ++miss_count;
      }
      
      if (miss_count == k) {
        return cur_num;
      }
    }
    
    while (miss_count != k) {
      ++cur_num;
      ++miss_count;
    }
    
    return cur_num;
  }
};

int main() {
  return 0;
}
