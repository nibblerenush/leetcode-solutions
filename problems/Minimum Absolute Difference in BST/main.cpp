#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  int getMinimumDifference(TreeNode* root) {
    if (!root) return result;
    
    getMinimumDifference(root->left);
    result = min(result, abs(root->val - prevVal));
    prevVal = root->val;
    getMinimumDifference(root->right);
    return result;
  }

private: 
  int result = numeric_limits<int>::max();
  int prevVal = numeric_limits<int>::max();
};

int main() {
  return 0;
}
