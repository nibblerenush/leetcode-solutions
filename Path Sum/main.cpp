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
  bool helper(TreeNode* root, int current_sum, int sum) {
    if (!root) {
      return false;
    }

    current_sum += root->val;
    if (!root->left && !root->right) {
      return current_sum == sum;
    }

    return helper(root->left, current_sum, sum) || helper(root->right, current_sum, sum);
  }

  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;
    }

    return helper(root, 0, sum);
  }
};

int main() {
  int sum = 0, n = 0;
  std::cin >> sum >> n;
  
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
  std::cout << std::boolalpha << solution.hasPathSum(root, sum) << std::endl;
  delete root;
  return 0;
}
