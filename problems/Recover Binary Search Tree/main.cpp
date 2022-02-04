#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  void recoverTree(TreeNode* root) {
    TreeNode max_node(numeric_limits<int>::max());
    TreeNode min_node(numeric_limits<int>::min());
    while (!is_valid_binary_tree(root, &min_node, &max_node)) {}
  }

private:
  bool is_valid_binary_tree(TreeNode* cur_node, TreeNode* min_node, TreeNode* max_node) {
    if (!cur_node) {
      return true;
    }

    if (cur_node->val < min_node->val) {
      swap(cur_node->val, min_node->val);
      return false;
    }
    else if (cur_node->val > max_node->val) {
      swap(cur_node->val, max_node->val);
      return false;
    }

    return
      is_valid_binary_tree(cur_node->left, min_node, cur_node) &&
      is_valid_binary_tree(cur_node->right, cur_node, max_node);
  }
};

int main() {
  return 0;
}
