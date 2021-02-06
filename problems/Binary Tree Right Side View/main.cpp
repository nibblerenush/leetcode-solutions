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
  vector<int> rightSideView(TreeNode* root) {
    // result
    vector<int> result;

    // prepare, part 1
    queue<pair<int, TreeNode*>> work_queue;
    work_queue.push({ 1, root });
    
    // prepare, part 2
    int last_level = 1;
    vector<int> last_row;
    
    while (!work_queue.empty()) {
      int cur_level = work_queue.front().first;
      TreeNode* cur_node = work_queue.front().second;
      work_queue.pop();

      if (!cur_node) {
        continue;
      }
      
      if (cur_level > last_level) {
        result.push_back(last_row.back());
        last_row.clear();
        last_level = cur_level;
      }
      last_row.push_back(cur_node->val);

      work_queue.push({ cur_level + 1, cur_node->left });
      work_queue.push({ cur_level + 1, cur_node->right });
    }

    if (!last_row.empty()) {
      result.push_back(last_row.back());
    }

    return result;
  }
};

int main() {
  return 0;
}
