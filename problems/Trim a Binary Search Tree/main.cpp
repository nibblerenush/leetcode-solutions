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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    result = root;
    traversal(root, nullptr, low, high);
    return result;
  }

private:
  void traversal(TreeNode* child, TreeNode* parent, int low, int high) {
    if (!child) {
      return;
    }
    
    if (child->val > high) {
      if (parent) {
        if (parent->left == child) {
          parent->left = child->left;
        }
        else {
          parent->right = child->left;
        }
      }
      else {
        result = child->left;
      }
      traversal(child->left, parent, low, high);
    }
    else if (child->val < low) {
      if (parent) {
        if (parent->left == child) {
          parent->left = child->right;
        }
        else {
          parent->right = child->right;
        }
      }
      else {
        result = child->right;
      }
      traversal(child->right, parent, low, high);
    }
    else {
      traversal(child->left, child, low, high);
      traversal(child->right, child, low, high);
    }
  }

private:
  TreeNode* result = nullptr;
};

int main() {
  return 0;
}
