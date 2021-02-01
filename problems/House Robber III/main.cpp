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
private:
  using dynamic_t = unordered_map<TreeNode*, int>;

public:
  int rob(TreeNode* root) {
    dynamic_t dynamic;
    dynamic[nullptr] = 0;
    traversal(root, dynamic);
    return dynamic[root];
  }

private:
  void traversal(TreeNode* root, dynamic_t& dynamic) {
    if (!root) {
      return;
    }
    
    traversal(root->left, dynamic);
    traversal(root->right, dynamic);
    
    int child_sum = dynamic[root->left] + dynamic[root->right];
    int root_sum = root->val +
      (root->left ? dynamic[root->left->left] + dynamic[root->left->right] : 0) +
      (root->right ? dynamic[root->right->left] + dynamic[root->right->right] : 0);
    
    dynamic[root] = max(child_sum, root_sum);
  }
};

int main() {
  return 0;
}
