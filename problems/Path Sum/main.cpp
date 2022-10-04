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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }

    return dfs(root, 0, targetSum);
  }

private:
  bool dfs(TreeNode* root, int currentSum, int targetSum) {
    if (!root) {
      return false;
    }
    
    currentSum += root->val;
    if (!root->left && !root->right) {
      return currentSum == targetSum;
    }

    return dfs(root->left, currentSum, targetSum) || dfs(root->right, currentSum, targetSum);
  }
};

int main() {
  return 0;
}
