#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return root;
    }

    TreeNode* del_node = root;
    TreeNode* prev_node = nullptr;

    while (del_node != nullptr && del_node->val != key) {
      prev_node = del_node;
      if (key > del_node->val) {
        del_node = del_node->right;
      }
      else {
        del_node = del_node->left;
      }
    }
    
    if (del_node == nullptr) {
      return root;
    }

    if (del_node->left == nullptr && del_node->right == nullptr) {
      if (prev_node == nullptr) {
        root = nullptr;
      }
      else {
        changeTree(prev_node, del_node, nullptr);
      }
    }
    else if (del_node->left == nullptr || del_node->right == nullptr) {
      if (del_node->left == nullptr) {
        if (prev_node == nullptr) {
          root = del_node->right;
        }
        else {
          changeTree(prev_node, del_node, del_node->right);
        }
      }
      else {
        if (prev_node == nullptr) {
          root = del_node->left;
        }
        else {
          changeTree(prev_node, del_node, del_node->left);
        }
      }
    }
    else {
      TreeNode* successor = del_node->right;
      TreeNode* prev_successor = nullptr;
      
      while (successor->left != nullptr) {
        prev_successor = successor;
        successor = successor->left;
      }

      del_node->val = successor->val;
      if (prev_successor != nullptr) {
        prev_successor->left = successor->right;
      }
      else {
        del_node->right = successor->right;
      }
    }

    return root;
  }

private:
  void changeTree(TreeNode* prev_node, TreeNode* del_node, TreeNode* change_node) {
    if (prev_node->left == del_node) {
      prev_node->left = change_node;
    }
    else {
      prev_node->right = change_node;
    }
  }
};

int main() {
  return 0;
}
