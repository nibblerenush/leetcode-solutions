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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    traverse(root);

    vector<TreeNode*> result;
    for (const auto& item : key_count) {
      if (item.second > 1) {
        result.push_back(key_treenode[item.first]);
      }
    }
    return result;
  }

private:
  string traverse(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    string key =
      to_string(root->val) + (root->left ? "_" : "#") + (root->right ? "_" : "?");
    
    string left_key = traverse(root->left);
    string right_key = traverse(root->right);
    key.append(left_key).append(right_key);
    
    key_treenode[key] = root;
    ++key_count[key];

    return key;
  }

private:
  unordered_map<string, TreeNode*> key_treenode;
  unordered_map<string, int> key_count;
};

int main() {
  return 0;
}
