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
  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }
    return traversal(root->left, root->right);
  }

private:
  bool traversal(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
      return true;
    }

    if (!left || !right) {
      return false;
    }
    
    return
      left->val == right->val &&
      traversal(left->left, right->right) &&
      traversal(left->right, right->left);
  }
};

int main() {
  return 0;
}
