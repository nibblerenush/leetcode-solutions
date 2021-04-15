#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    stack<TreeNode*> even_stack;
    stack<TreeNode*> odd_stack;
    
    if (root) {
      even_stack.push(root);
    }
    
    vector<int> row;
    
    auto add_row = [&row, &result]() {
      if (!row.empty()) {
        result.push_back(move(row));
      }
    };
    
    auto add_to_stack = [](TreeNode* node, stack<TreeNode*>& work_stack) {
      if (node) {
        work_stack.push(node);
      }
    };
    
    while (!even_stack.empty() || !odd_stack.empty()) {
      while (!even_stack.empty()) {
        TreeNode* node = even_stack.top();
        even_stack.pop();
        
        row.push_back(node->val);
        
        add_to_stack(node->left, odd_stack);
        add_to_stack(node->right, odd_stack);
      }
      add_row();
      
      while (!odd_stack.empty()) {
        TreeNode* node = odd_stack.top();
        odd_stack.pop();

        row.push_back(node->val);
        
        add_to_stack(node->right, even_stack);
        add_to_stack(node->left, even_stack);
      }
      add_row();
    }
    
    return result;
  }
};

int main() {
  return 0;
}
