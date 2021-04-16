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

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node* connect(Node* root) {
    Node* cur_left = root;

    while (cur_left) {
      Node* cur_level = cur_left;

      while (cur_level && cur_level->left && cur_level->right) {
        cur_level->left->next = cur_level->right;
        cur_level->right->next = cur_level->next ? cur_level->next->left : nullptr;
        cur_level = cur_level->next;
      }

      cur_left = cur_left->left;
    }

    return root;
  }
};

int main() {
  return 0;
}
