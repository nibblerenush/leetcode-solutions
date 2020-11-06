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
  
  void helper(TreeNode*& node, vector_t in, int li, int ri, vector_t post, int lp, int rp) {
    if (li > ri || lp > rp) {
      return;
    }

    node = new TreeNode(post[rp]);
    
    int mid_in = 0;
    for (int i = li; i <= ri; ++i) {
      if (in[i] == post[rp]) {
        mid_in = i;
        break;
      }
    }

    helper(node->left, in, li, mid_in - 1, post, lp, lp + mid_in - li - 1);
    helper(node->right, in, mid_in + 1, ri, post, rp - ri + mid_in, rp - 1);
  }

  TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    TreeNode* root = nullptr;
    helper(root, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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

  std::vector<int> inorder(n);
  std::vector<int> postorder(n);

  for (auto& val : inorder) {
    std::cin >> val;
  }
  for (auto& val : postorder) {
    std::cin >> val;
  }
  
  Solution solution;
  TreeNode* root = solution.buildTree(inorder, postorder);
  PrintInOrder(root);
  std::cout << std::endl;
  delete root;
  return 0;
}
