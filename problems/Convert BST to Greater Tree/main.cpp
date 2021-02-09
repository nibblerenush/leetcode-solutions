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
  TreeNode* convertBST(TreeNode* root) {
    count = 0;
    dfs(root);
    return root;
  }

private:
  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }
    
    dfs(root->right);
    
    // right inorder
    count += root->val;
    root->val = count;
    
    dfs(root->left);
  }

private:
  int count = 0;
};

int main() {
  return 0;
}
