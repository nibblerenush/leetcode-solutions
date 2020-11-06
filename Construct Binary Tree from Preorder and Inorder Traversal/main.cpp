#include <iostream>

#include <algorithm>
#include <iostream>
#include <vector>

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
  using vector_t = const std::vector<int>&;

  void helper(TreeNode*& node, vector_t pre, int lp, int rp, vector_t in, int li, int ri) {
    if (lp > rp || li > ri) {
      return;
    }

    node = new TreeNode(pre[lp]);
    
    int mid_in = 0;
    for (int i = li; i <= ri; ++i) {
      if (in[i] == pre[lp]) {
        mid_in = i;
        break;
      }
    }
    helper(node->left, pre, lp + 1, lp + mid_in - li, in, li, mid_in - 1);
    helper(node->right, pre, rp - ri + mid_in + 1 , rp, in, mid_in + 1, ri);
  }

  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    TreeNode* root = nullptr;
    helper(root, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
  }
};

void PrintInOrder(TreeNode* root) {
  if (!root) {
    return;
  }

  PrintInOrder(root->left);
  std::cout << root->val << ' ';
  PrintInOrder(root->right);
}

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> preorder(n);
  std::vector<int> inorder(n);

  for (auto& val : preorder) {
    std::cin >> val;
  }
  for (auto& val : inorder) {
    std::cin >> val;
  }
  
  Solution solution;
  TreeNode* root = solution.buildTree(preorder, inorder);
  PrintInOrder(root);
  std::cout << std::endl;
  delete root;
  return 0;
}
