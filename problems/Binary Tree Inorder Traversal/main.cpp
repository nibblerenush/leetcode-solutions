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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    
    stack<TreeNode*> work_stack;
    TreeNode* cur_node = root;
    
    while (!work_stack.empty() || cur_node) {
      while (cur_node) {
        work_stack.push(cur_node);
        cur_node = cur_node->left;
      }
      
      cur_node = work_stack.top();
      work_stack.pop();
      
      result.push_back(cur_node->val);
      cur_node = cur_node->right;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
