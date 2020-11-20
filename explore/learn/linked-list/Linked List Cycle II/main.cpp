#include <algorithm>
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) {
      return nullptr;
    }
    ListNode* slow_runner = head;
    ListNode* fast_runner = head->next;
    
    while (slow_runner && fast_runner) {
      if (slow_runner == fast_runner) {
        while (true) {
          ListNode* ptr_node1 = getPtrNode(head, slow_runner);
          ListNode* ptr_node2 = getPtrNode(slow_runner->next, slow_runner);
          
          if (ptr_node1 == ptr_node2) {
            if (ptr_node1 == head) {
              return head;
            }
            else {
              slow_runner = slow_runner->next;
            }
          }
          else {
            return slow_runner;
          }
        }
      }
      
      slow_runner = slow_runner->next;
      fast_runner = fast_runner->next ? fast_runner->next->next : nullptr;
    }
    return nullptr;
  }

private:
  ListNode* getPtrNode(ListNode* from, ListNode* to) {
    while (from->next != to) {
      from = from->next;
    }
    return from;
  }
};

int main() {
  int pos = 0, n = 0;
  std::cin >> pos >> n;
  
  ListNode* head = nullptr;
  ListNode* pos_node = nullptr;
  ListNode* cur_node = nullptr;
  int cur_index = -1;
  
  for (int i = 0; i < n; ++i) {
    int val = 0;
    std::cin >> val;
    ListNode* new_node = new ListNode{ val };
    ++cur_index;
    
    if (cur_index == pos) {
      pos_node = new_node;
    }
    
    if (cur_node) {
      cur_node->next = new_node;
      cur_node = cur_node->next;
    }
    else {
      cur_node = new_node;
      head = cur_node;
    }
  }

  if (cur_node) {
    cur_node->next = pos_node;
  }

  Solution solution;
  std::cout << solution.detectCycle(head)->val << std::endl;
  return 0;
}
