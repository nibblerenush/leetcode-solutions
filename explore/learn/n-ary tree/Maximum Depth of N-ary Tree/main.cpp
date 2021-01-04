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
  int maxDepth(Node* root) {
    return Height(root);
  }

private:
  int Height(Node* root) {
    if (root) {
      int height = 1;
      for (Node* node : root->children) {
        height = max(height, 1 + Height(node));
      }
      return height;
    }
    return 0;
  }
};

int main() {
  return 0;
}
