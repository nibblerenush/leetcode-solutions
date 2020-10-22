#include <iostream>

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

class Solution {
public:
  void traverse(TreeNode* root, int counter, int& result) {
    if (!root) {
      return;
    }

    counter++;
    if (!root->left && !root->right && counter < result) {
      result = counter;
    }

    traverse(root->left, counter, result);
    traverse(root->right, counter, result);
  }

  int minDepth(TreeNode* root) {
    int result = std::numeric_limits<int>::max();
    traverse(root, 0, result);
    return result == std::numeric_limits<int>::max() ? 0 : result;
  }
};

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  
  Solution solution;
  std::cout << solution.minDepth(root) << std::endl;
  return 0;
}
