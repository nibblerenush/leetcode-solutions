#include <iostream>
#include <queue>
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
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
      return result;
    }

    std::queue<std::pair<int, TreeNode*>> work_queue;
    work_queue.push({ 1, root });
    int last_level = 1;
    std::vector<int> last_row;

    while (!work_queue.empty()) {
      int cur_level = work_queue.front().first;
      TreeNode* cur = work_queue.front().second;
      work_queue.pop();

      if (!cur) {
        continue;
      }

      if (cur_level == last_level) {
        last_row.push_back(cur->val);
      }
      else if (cur_level > last_level) {
        result.push_back(last_row);
        last_row.clear();
        last_row.push_back(cur->val);
        last_level = cur_level;
      }

      work_queue.push({ cur_level + 1, cur->left });
      work_queue.push({ cur_level + 1, cur->right });
    }

    result.push_back(last_row);
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
  auto results = solution.levelOrder(root);
  for (const auto& row : results) {
    for (const auto& val : row) {
      std::cout << val << ' ';
    }
    std::cout << std::endl;
  }
  delete root;
  return 0;
}
