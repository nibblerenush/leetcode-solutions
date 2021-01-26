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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* result = nullptr;
    traversal(root, p, q, &result);
    return result;
  }

private:
  int traversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** result) {
    if (!root) {
      return 0;
    }
    
    int left_num = traversal(root->left, p, q, result);
    int right_num = traversal(root->right, p, q, result);
    
    if (*result) {
      return 0;
    }
    
    int num = (root == p || root == q ? 1 : 0) + left_num + right_num;
    if (num == 2) {
      *result = root;
    }
    
    return num;
  }
};

int main() {
  return 0;
}
