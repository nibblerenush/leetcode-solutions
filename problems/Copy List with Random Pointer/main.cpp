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
    
    Node* result_head = nullptr;
    Node* cur_node_old = head;
    Node* cur_node_new = result_head;
    unordered_map<Node*, Node*> old_new;
    
    while (cur_node_old) {
      if (result_head) {
        cur_node_new->next = new Node(cur_node_old->val);
        cur_node_new = cur_node_new->next;
      }
      else {
        result_head = new Node(cur_node_old->val);
        cur_node_new = result_head;
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
    
    return result_head;
  }
};

int main() {
  return 0;
}
