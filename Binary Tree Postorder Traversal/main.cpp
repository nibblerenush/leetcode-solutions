#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

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
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> work_stack;
    std::stack<TreeNode*> help_stack;
    
    work_stack.push(root);
    TreeNode* cur_node = root;
    
    while (!work_stack.empty()) {
      while (cur_node != nullptr) {
        work_stack.push(cur_node->left);
        cur_node = cur_node->left;
      }
      
      cur_node = work_stack.top();
      if (!cur_node) {
        work_stack.pop();
      }
      else {
        if (cur_node->right) {
          if (!help_stack.empty() && work_stack.top() == help_stack.top()) {
            result.push_back(work_stack.top()->val);
            work_stack.pop();
            help_stack.pop();
            cur_node = nullptr;
          }
          else {
            help_stack.push(cur_node);
            work_stack.push(cur_node->right);
            cur_node = cur_node->right;
          }
        }
        else {
          work_stack.pop();
          result.push_back(cur_node->val);
          cur_node = nullptr;
        }
      }
    }
    
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
  auto vals = solution.postorderTraversal(root);
  for (auto val : vals) {
    std::cout << val << ' ';
  }
  std::cout << std::endl;
  delete root;
  return 0;
}
