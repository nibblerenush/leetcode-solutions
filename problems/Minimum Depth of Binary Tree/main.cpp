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
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int result = numeric_limits<int>::max();
    dfs(root, 0, result);
    return result;
  }

private:
  void dfs(TreeNode* root, int depth, int& minDepth) {
    if (!root) {
      return;
    }

    ++depth;
    if (root->left == nullptr && root->right == nullptr) {
      minDepth = min(depth, minDepth);
    }

    dfs(root->left, depth, minDepth);
    dfs(root->right, depth, minDepth);
  }
};

int main() {
  return 0;
}
