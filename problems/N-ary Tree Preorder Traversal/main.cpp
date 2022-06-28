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
  vector<int> preorder(Node* root) {
    vector<int> preorderVector;
    getPreorder(root, preorderVector);
    return preorderVector;
  }

private:
  void getPreorder(const Node* root, vector<int>& preorderVector)
  {
    if (!root) return;

    preorderVector.push_back(root->val);
    for (const Node* node : root->children)
    {
      getPreorder(node, preorderVector);
    }
  }
};

int main() {
  return 0;
}
