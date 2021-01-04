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
  vector<int> postorder(Node* root) {
    traverse(root);
    return result;
  }

private:
  void traverse(Node* root) {
    if (root) {
      for (Node* child : root->children) {
        traverse(child);
      }
      result.push_back(root->val);
    }
  }

private:
  vector<int> result;
};

int main() {
  return 0;
}
