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
  void helper_left(TreeNode* root, std::string& id) {
    if (!root) {
      id += '$';
      return;
    }
    
    id += std::to_string(root->val);
    helper_left(root->left, id);
    helper_left(root->right, id);
  }

  void helper_right(TreeNode* root, std::string& id) {
    if (!root) {
      id += '$';
      return;
    }
    
    id += std::to_string(root->val);
    helper_right(root->right, id);
    helper_right(root->left, id);
  }

  bool isSymmetric(TreeNode* root) {
    std::string id_left, id_right;
    helper_left(root, id_left);
    helper_right(root, id_right);
    return id_left == id_right;
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  
  TreeNode* root = nullptr;
  TreeNode* cur_node = nullptr;
  std::queue<TreeNode*> work_queue;
  
  auto get_val = [](const std::string& val) -> TreeNode* {
    return val == "null" ? nullptr : new TreeNode{ std::stoi(val) };
  };
  
  for (int i = 0; i < n; ++i) {
    std::string val;
    std::cin >> val;
    
    if (i == 0) {
      root = get_val(val);
      work_queue.push(root);
      continue;
    }
    
    if (i % 2 != 0) {
      cur_node = work_queue.front();
      work_queue.pop();
      
      if (cur_node) {
        cur_node->left = get_val(val);
        work_queue.push(cur_node->left);
      }
    }
    else {
      if (cur_node) {
        cur_node->right = get_val(val);
        work_queue.push(cur_node->right);
      }
    }
  }

  Solution solution;
  std::cout << std::boolalpha << solution.isSymmetric(root) << std::endl;
  delete root;
  return 0;
}
