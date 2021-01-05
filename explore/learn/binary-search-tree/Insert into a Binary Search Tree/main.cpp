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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    TreeNode* cur_node = root;
    TreeNode* prev_node = nullptr;

    while (cur_node != nullptr) {
      prev_node = cur_node;
      if (val > cur_node->val) {
        cur_node = cur_node->right;
      }
      else {
        cur_node = cur_node->left;
      }
    }

    if (val > prev_node->val) {
      prev_node->right = new TreeNode(val);
    }
    else {
      prev_node->left = new TreeNode(val);
    }
    return root;
  }
};

int main() {
  return 0;
}
