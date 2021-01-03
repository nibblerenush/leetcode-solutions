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

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    return (abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
  }

private:
  int height(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }
};

int main() {
  return 0;
}
