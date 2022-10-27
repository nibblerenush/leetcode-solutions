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
  int maxLevelSum(TreeNode* root) {
    int maxSum = numeric_limits<int>::min();
    int maxLevel = 0;
    
    queue<pair<int, TreeNode*>> levelNodeQueue;
    if (root) {
      levelNodeQueue.push({ 1, root });
    }
    int curLevel = 1;
    int curSum = 0;

    while (!levelNodeQueue.empty()) {
      auto item = levelNodeQueue.front();
      levelNodeQueue.pop();

      if (item.first == curLevel) {
        curSum += item.second->val;
      }
      else {
        if (curSum > maxSum) {
          maxSum = curSum;
          maxLevel = curLevel;
        }
        curLevel = item.first;
        curSum = item.second->val;
      }

      if (item.second->left) {
        levelNodeQueue.push({ item.first + 1, item.second->left });
      }

      if (item.second->right) {
        levelNodeQueue.push({ item.first + 1, item.second->right });
      }
    }

    // Post processing
    if (curSum > maxSum) {
      maxSum = curSum;
      maxLevel = curLevel;
    }

    return maxLevel;
  }
};

int main() {
  return 0;
}
