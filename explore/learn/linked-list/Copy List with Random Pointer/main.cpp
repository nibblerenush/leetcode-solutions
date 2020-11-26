#include <iostream>
#include <unordered_map>
#include <utility>

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    
    Node* result = nullptr;
    Node* cur_node_old = head;
    Node* cur_node_new = result;
    std::unordered_map<Node*, Node*> old_new;

    while (cur_node_old) {
      if (result) {
        cur_node_new->next = new Node(cur_node_old->val);
        cur_node_new = cur_node_new->next;
      }
      else {
        result = new Node(cur_node_old->val);
        cur_node_new = result;
      }
      old_new.emplace(cur_node_old, cur_node_new);
      cur_node_old = cur_node_old->next;
    }

    cur_node_old = head;
    while (cur_node_old) {
      Node* new_node = old_new[cur_node_old];
      Node* randow_new_node = old_new[cur_node_old->random];
      new_node->random = randow_new_node;
      cur_node_old = cur_node_old->next;
    }

    return result;
  }
};

void Delete(Node* head) {
  while (head) {
    Node* next = head->next;
    delete head;
    head = next;
  }
}

void PrintLinkedList(Node* head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  Node* head = new Node(3);
  head->next = new Node(3);
  head->next->next = new Node(3);
  head->next->random = head;
    
  Solution solution;
  Node* result = solution.copyRandomList(head);
  PrintLinkedList(result);

  Delete(head);
  Delete(result);
  return 0;
}
