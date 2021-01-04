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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    string path;
    traverse(original, target, "", path);
    
    TreeNode* result = cloned;
    for (char c : path) {
      if (c == 'l') {
        result = result->left;
      }
      else {
        result = result->right;
      }
    }
    return result;
  }

private:
  void traverse(TreeNode* root, TreeNode* target, string path, string& result_path) {
    if (!root || !result_path.empty()) {
      return;
    }
    
    if (root == target) {
      result_path = move(path);
      return;
    }

    traverse(root->left, target, path + 'l', result_path);
    traverse(root->right, target, path + 'r', result_path);
  }
};

int main() {
  return 0;
}
