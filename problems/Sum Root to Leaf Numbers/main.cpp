#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    return traversal(root, 0);
  }

private:
  int traversal(TreeNode* cur_node, int cur_number) {
    if (!cur_node) {
      return 0;
    }
    
    if (!cur_node->left && !cur_node->right) {
      return 10 * cur_number + cur_node->val;
    }

    return traversal(cur_node->left, 10 * cur_number + cur_node->val) +
      traversal(cur_node->right, 10 * cur_number + cur_node->val);
  }
};

int main() {
  return 0;
}
