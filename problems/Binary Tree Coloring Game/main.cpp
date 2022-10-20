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
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    findNode(root, x);
    int lSubtree = countNodes(xNode->left);
    int rSubtree = countNodes(xNode->right);
    int pSubtree = n - lSubtree - rSubtree - 1;

    return
      (pSubtree > lSubtree + rSubtree + 1) ||
      (lSubtree > pSubtree + rSubtree + 1) ||
      (rSubtree > pSubtree + lSubtree + 1);
  }

private:
  void findNode(TreeNode* root, int x) {
    if (!root || xNode) {
      return;
    }

    if (root->val == x) {
      xNode = root;
    }

    findNode(root->left, x);
    findNode(root->right, x);
  }
  
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  TreeNode* xNode = nullptr;
};

int main() {
  return 0;
}
