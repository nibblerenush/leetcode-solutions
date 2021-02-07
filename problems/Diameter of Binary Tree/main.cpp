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
  int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return result;
  }

private:
  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }
    
    int left_path = dfs(root->left);
    int right_path = dfs(root->right);
    
    result = max(result, left_path + right_path);
    return 1 + max(left_path, right_path);
  }

private:
  int result = 0;
};

int main() {
  return 0;
}
