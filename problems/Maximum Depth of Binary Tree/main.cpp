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
  int maxDepth(TreeNode* root) {
    return traversal(root, 1);
  }

private:
  int traversal(TreeNode* root, int depth) {
    if (!root) {
      return 0;
    }
    
    if (!root->left && !root->right) {
      return depth;
    }
    
    return max(traversal(root->left, depth + 1), traversal(root->right, depth + 1));
  }
};

int main() {
  return 0;
}
