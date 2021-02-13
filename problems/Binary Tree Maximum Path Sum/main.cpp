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
  int maxPathSum(TreeNode* root) {
    int path_sum = dfs(root);
    return max(result, path_sum);
  }

private:
  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }
    
    int left_sum = dfs(root->left);
    int right_sum = dfs(root->right);

    int path_sum = max({
      root->val,
      root->val + left_sum,
      root->val + right_sum,
      root->val + left_sum + right_sum });
    result = max(result, path_sum);
    
    return max(root->val, root->val + max(left_sum, right_sum));
  }

private:
  int result = numeric_limits<int>::min();
};

int main() {
  return 0;
}
