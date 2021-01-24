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
  int findKthLargest(vector<int>& nums, int k) {
    int size = nums.size();
    return nums[divide_and_conquer(nums, 0, size - 1, size - k)];
  }

private:
  int divide_and_conquer(vector<int>& nums, int left, int right, int k) {
    int size = nums.size();
    
    if (left >= 0 && left < size && right >= 0 && right < size && left <= right) {
      int pivot_index = partition(nums, left, right);
      
      if (pivot_index == k) {
        return pivot_index;
      }
      else if (pivot_index < k) {
        return divide_and_conquer(nums, pivot_index + 1, right, k);
      }
      else {
        return divide_and_conquer(nums, left, pivot_index - 1, k);
      }
    }
    
    return -1;
  }
  
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    
    for (int j = left; j < right; ++j) {
      if (nums[j] <= pivot) {
        swap(nums[j], nums[i++]);
      }
    }
    
    swap(nums[i], nums[right]);
    return i;
  }
};

int main() {
  return 0;
}
