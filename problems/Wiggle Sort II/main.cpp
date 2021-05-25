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
  void wiggleSort(vector<int>& nums) {
    const int MAX_VALUE = 5000;
    vector<int> count(MAX_VALUE + 1, 0);
    
    for (int num : nums) {
      count[num] += 1;
    }
    
    int j = MAX_VALUE;
    fill_cells(1, nums, j, count);
    fill_cells(0, nums, j, count);
  }

private:
  void fill_cells(int start_index, vector<int>& nums, int& end_index, vector<int>& count) {
    int i = start_index;
    int j = end_index;
    
    while (i < (int)nums.size()) {
      while (count[j] == 0) {
        j -= 1;
      }
      
      count[j] -= 1;
      nums[i] = j;
      i += 2;
    }
  }
};

int main() {
  return 0;
}
