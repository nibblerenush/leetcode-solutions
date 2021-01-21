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
  bool isValidBST(TreeNode* root) {
    return traversal(root, numeric_limits<long long>::max(), numeric_limits<long long>::min());
  }

private:
  bool traversal(TreeNode* root, long long max, long long min) {
    if (!root) {
      return true;
    }
    
    if (root->val >= max || root->val <= min) {
      return false;
    }
    
    return traversal(root->left, root->val, min) && traversal(root->right, max, root->val);
  }
};

int main() {
  return 0;
}
