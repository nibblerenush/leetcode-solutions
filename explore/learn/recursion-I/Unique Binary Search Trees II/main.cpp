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
  std::vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    return helper(1, n);
  }

private:
  std::vector<TreeNode*> helper(int start, int end) {
    std::vector<TreeNode*> result;
    if (start > end) {
      result.push_back(nullptr);
      return result;
    }

    for (int i = start; i <= end; ++i) {
      auto left_nodes = helper(start, i - 1);
      auto right_nodes = helper(i + 1, end);

      for (auto left : left_nodes) {
        for (auto right : right_nodes) {
          TreeNode* new_node = new TreeNode(i);
          new_node->left = left;
          new_node->right = right;
          result.push_back(new_node);
        }
      }
    }

    return result;
  }
};

void PrintTree(TreeNode* root) {
  if (!root) {
    return;
  }
  
  std::cout << root->val << ' ';
  PrintTree(root->left);
  PrintTree(root->right);
}

int main() {
  int n = 0;
  std::cin >> n;

  Solution solution;
  auto result = solution.generateTrees(n);

  for (auto root : solution.generateTrees(n)) {
    PrintTree(root);
    std::cout << std::endl;
  }
  return 0;
}
