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
  TreeNode* invertTree(TreeNode* root) {
    traversal(root);
    return root;
  }

private:
  void traversal(TreeNode* root) {
    if (!root) {
      return;
    }

    swap(root->left, root->right);

    traversal(root->left);
    traversal(root->right);
  }
};

int main() {
  return 0;
}
