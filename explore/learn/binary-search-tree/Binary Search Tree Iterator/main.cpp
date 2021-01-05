#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    cur_node = root;
  }
  
  int next() {
    int result = 0;
    
    while (cur_node != nullptr) {
      work_stack.push(cur_node);
      cur_node = cur_node->left;
    }
    
    cur_node = work_stack.top();
    work_stack.pop();
    
    result = cur_node->val;
    cur_node = cur_node->right;
    return result;
  }

  bool hasNext() {
    return !work_stack.empty() || cur_node != nullptr;
  }

private:
  TreeNode* cur_node;
  stack<TreeNode*> work_stack;
};

int main() {
  return 0;
}
