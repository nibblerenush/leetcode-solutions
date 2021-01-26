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
    traversal(root, p, q, result);
    return result;
  }

private:
  unordered_set<int> traversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result) {
    if (!root) {
      return {};
    }
    
    auto left_set = traversal(root->left, p, q, result);
    auto right_set = traversal(root->right, p, q, result);
    
    if (result) {
      return {};
    }
    
    unordered_set<int> root_set;
    for (int val : left_set) {
      root_set.insert(val);
    }
    for (int val : right_set) {
      root_set.insert(val);
    }
    
    if (root->val == p->val || root->val == q->val) {
      root_set.insert(root->val);
    }
    
    if (root_set.count(p->val) && root_set.count(q->val)) {
      result = root;
    }
    
    return root_set;
  }  
};

int main() {
  return 0;
}
