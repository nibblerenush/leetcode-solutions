#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

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
  std::unordered_set<int> helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result) {
    if (!root) {
      return {};
    }

    auto left_set = helper(root->left, p, q, result);
    auto right_set = helper(root->right, p, q, result);

    if (result) {
      return {};
    }
    
    std::unordered_set<int> root_set;
    for (int val : left_set) {
      root_set.insert(val);
    }
    for (int val : right_set) {
      root_set.insert(val);
    }
    
    if (root->val == p->val || root->val == q->val) {
      root_set.insert(root->val);
    }
    
    if (root_set.count(p->val) && root_set.count(q->val)) {
      result = root;
    }

    return root_set;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* result = nullptr;
    helper(root, p, q, result);
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
  TreeNode* lca = solution.lowestCommonAncestor(root, root->left, root->right);
  std::cout << lca->val << std::endl;
  delete root;
  return 0;
}
