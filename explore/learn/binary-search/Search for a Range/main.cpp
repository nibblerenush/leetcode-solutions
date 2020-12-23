#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  enum class Edge {
    LEFT,
    RIGHT
  };

public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return { -1, -1 };
    }

    vector<int> search_range(2);
    search_range[0] = binary_search<Edge::LEFT>(nums, target, &is_left_target);
    search_range[1] = binary_search<Edge::RIGHT>(nums, target, &is_right_target);
    return search_range;
  }

private:
  template <Edge edge, typename Func>
  int binary_search(vector<int>& nums, int target, Func is_edge_target) {
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (is_edge_target(nums, mid, target)) {
        return mid;
      }
      else if (nums[mid] == target) {
        if (edge == Edge::LEFT) {
          right = mid;
        }
        else {
          left = mid;
        }
      }
      else if (nums[mid] < target) {
        left = mid;
      }
      else {
        right = mid;
      }
    }

    if (is_edge_target(nums, left, target)) {
      return left;
    }

    if (is_edge_target(nums, right, target)) {
      return right;
    }

    return -1;
  }

  static bool is_left_target(const vector<int>& nums, int index, int target) {
    int left_index = index - 1;
    bool is_mid_equal = nums[index] == target;
    bool is_left_smaller = left_index >= 0 ? nums[left_index] < target : true;
    return is_mid_equal && is_left_smaller;
  }

  static bool is_right_target(const vector<int>& nums, int index, int target) {
    int size = nums.size();
    int right_index = index + 1;
    bool is_mid_equal = nums[index] == target;
    bool is_right_bigger = right_index < size ? nums[right_index] > target : true;
    return is_mid_equal && is_right_bigger;
  }
};

int main() {
  int target, n;
  cin >> target >> n;

  vector<int> nums(n);
  for (auto& num : nums) {
    cin >> num;
  }

  Solution solution;
  for (const auto& num : solution.searchRange(nums, target)) {
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}
