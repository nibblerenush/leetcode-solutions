#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) {
      return {};
    }

    vector<vector<int>> result;
    queue<pair<int, Node*>> work_queue;
    work_queue.push({ 1, root });
    int cur_level = 0;

    while (!work_queue.empty()) {
      int level = work_queue.front().first;
      Node* node = work_queue.front().second;
      work_queue.pop();

      if (level > cur_level) {
        cur_level = level;
        result.push_back(vector<int>{ node->val });
      }
      else {
        result.back().push_back(node->val);
      }

      for (Node* child : node->children) {
        work_queue.push({ level + 1, child });
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
