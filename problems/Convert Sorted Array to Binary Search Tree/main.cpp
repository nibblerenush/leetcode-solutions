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


struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* result = nullptr;
    divide_and_conquer(nums, 0, nums.size() - 1, result);
    return result;
  }

private:
  void divide_and_conquer(const vector<int>& nums, int left, int right, TreeNode*& node) {
    int size = nums.size();
    if (left >= 0 && right < size && left <= right) {
      int mid = left + (right - left) / 2;
      node = new TreeNode(nums[mid]);
      divide_and_conquer(nums, left, mid - 1, node->left);
      divide_and_conquer(nums, mid + 1, right, node->right);
    }
  }
};

int main() {
  return 0;
}
