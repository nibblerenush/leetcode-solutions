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
  int pathSum(TreeNode* root, int sum) {
    this->sum = sum;
    traversal(root);
    return result;
  }

private:
  void traversal(TreeNode* root) {
    if (!root) {
      return;
    }
    
    // with cur root
    calc_pathsum(root, 0);
    
    // with new roots
    traversal(root->left);
    traversal(root->right);
  }
  
  void calc_pathsum(TreeNode* root, int cur_pathsum) {
    if (!root) {
      return;
    }
    
    cur_pathsum += root->val;
    if (cur_pathsum == sum) {
      result += 1;
    }
    
    calc_pathsum(root->left, cur_pathsum);
    calc_pathsum(root->right, cur_pathsum);
  }

private:
  int sum = 0;
  int result = 0;
};

int main() {
  return 0;
}
