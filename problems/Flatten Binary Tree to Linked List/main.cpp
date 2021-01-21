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
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        swap(root->left, root->right);
        TreeNode* right = root->left;
        root->left = nullptr;
        
        TreeNode* cur_node = root;
        while (cur_node->right) {
          cur_node = cur_node->right;
        }
        cur_node->right = right;
      }
      
      root = root->right;
    }
  }
};

int main() {
  return 0;
}
