#include <iostream>

class Node {
public:
  int val;
  Node* prev = nullptr;
  Node* next = nullptr;
  Node* child = nullptr;
  ~Node() {
    delete next;
    delete child;
  }
};

class Solution {
public:
  void helper(Node* head, Node*& cur_node, Node*& result) {
    if (!head) {
      return;
    }

    if (!result) {
      result = new Node{ head->val };
      cur_node = result;
    }
    else {
      Node* prev_node = cur_node;
      cur_node->next = new Node{ head->val };
      cur_node = cur_node->next;
      cur_node->prev = prev_node;
    }

    helper(head->child, cur_node, result);
    helper(head->next, cur_node, result);
  }

  Node* flatten(Node* head) {
    Node* result = nullptr;
    Node* cur_node = nullptr;
    helper(head, cur_node, result);
    return result;
  }
};

int main() {
  Node* head = new Node{ 1 };
  head->next = new Node{ 2 };
  head->child = new Node{ 3 };

  Solution solution;
  Node* result = solution.flatten(head);
  while (result) {
    std::cout << result->val << ' ';
    result = result->next;
  }
  std::cout << std::endl;

  delete head;
  delete result;
  return 0;
}
