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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = nullptr;
    divide_and_conquer(root, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
  }

private:
  using vector_t = const vector<int>&;
  
  void divide_and_conquer(TreeNode*& node, vector_t pre, int lp, int rp, vector_t in, int li, int ri) {
    if (lp > rp || li > ri) {
      return;
    }
    
    node = new TreeNode(pre[lp]);
    
    int mid_in = 0;
    for (int i = li; i <= ri; ++i) {
      if (in[i] == pre[lp]) {
        mid_in = i;
        break;
      }
    }
    
    divide_and_conquer(node->left, pre, lp + 1, lp + mid_in - li, in, li, mid_in - 1);
    divide_and_conquer(node->right, pre, rp - ri + mid_in + 1 , rp, in, mid_in + 1, ri);
  }
};

int main() {
  return 0;
}
