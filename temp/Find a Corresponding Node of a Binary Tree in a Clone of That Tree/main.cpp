#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    traverse(original, cloned, target);
    return result;
  }

private:
  void traverse(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original || result) {
      return;
    }

    if (original == target) {
      result = cloned;
      return;
    }

    traverse(original->left, cloned->left, target);
    traverse(original->right, cloned->right, target);
  }

private:
  TreeNode* result = nullptr;
};

int main() {
  return 0;
}
