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
  void helper(TreeNode* root, int depth, int& result) {
    if (!root) {
      return;
    }
    
    if (!root->left && !root->right) {
      result = std::max(result, depth);
    }

    helper(root->left, depth + 1, result);
    helper(root->right, depth + 1, result);
  }

  int maxDepth(TreeNode* root) {
    int result = 0;
    helper(root, 1, result);
    return result;
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
  std::cout << solution.maxDepth(root) << std::endl;
  delete root;
  return 0;
}
