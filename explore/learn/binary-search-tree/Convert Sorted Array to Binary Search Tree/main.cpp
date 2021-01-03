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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

void PrintInOrder(TreeNode* root) {
  if (!root) {
    return;
  }

  PrintInOrder(root->left);
  cout << root->val << ' ';
  PrintInOrder(root->right);
}

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
  vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  Solution solution;
  auto result = solution.sortedArrayToBST(nums);
  PrintInOrder(result);
  return 0;
}
