#include <iostream>
#include <queue>
#include <string>

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
  TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) {
      return nullptr;
    }

    if (root->val == val) {
      return root;
    }
    else if (val < root->val) {
      return searchBST(root->left, val);
    }
    else {
      return searchBST(root->right, val);
    }
  }
};

int main() {
  int val = 0, n = 0;
  std::cin >> val >> n;
  
  std::queue<std::string> val_queue;
  for (int i = 0; i < n; ++i) {
    std::string val;
    std::cin >> val;
    val_queue.push(std::move(val));
  }
  
  TreeNode* root = nullptr;
  if (!val_queue.empty()) {
    auto get_val = [](const std::string& val) -> TreeNode* {
      return val == "null" ? nullptr : new TreeNode{ std::stoi(val) };
    };
    
    root = get_val(val_queue.front());
    val_queue.pop();

    std::queue<TreeNode*> tree_queue;
    tree_queue.push(root);

    while (!tree_queue.empty()) {
      TreeNode* cur_node = tree_queue.front();
      tree_queue.pop();

      if (!cur_node) {
        continue;
      }

      if (!val_queue.empty()) {
        cur_node->left = get_val(val_queue.front());
        val_queue.pop();
      }

      if (!val_queue.empty()) {
        cur_node->right = get_val(val_queue.front());
        val_queue.pop();
      }

      tree_queue.push(cur_node->left);
      tree_queue.push(cur_node->right);
    }
  }

  Solution solution;
  TreeNode* result = solution.searchBST(root, val);
  if (result) {
    std::cout << result->val << std::endl;
  }

  delete root;
  return 0;
}
