#include <iostream>
#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

void Delete(ListNode* head) {
  while (head) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
      return head;
    }
    
    ListNode* cur_node = head;
    ListNode* next_node = head;
    for (int i = 0; i < n; ++i) {
      next_node = next_node->next;
    }
    
    ListNode* prev_node = nullptr;
    while (next_node) {
      prev_node = cur_node;
      cur_node = cur_node->next;
      next_node = next_node->next;
    }
    
    if (cur_node) {
      if (prev_node) {
        prev_node->next = cur_node->next;
      }
      else {
        head = cur_node->next;
      }
      delete cur_node;
    }

    return head;
  }
};

int main() {
  int number = 0, n = 0;
  std::cin >> number >> n;
  
  ListNode* head = nullptr;
  ListNode* cur_node = nullptr;
  
  for (int i = 0; i < n; ++i) {
    int val = 0;
    std::cin >> val;
    ListNode* new_node = new ListNode{ val };
    
    if (cur_node) {
      cur_node->next = new_node;
      cur_node = cur_node->next;
    }
    else {
      cur_node = new_node;
      head = cur_node;
    }
  }
  
  Solution solution;
  head = solution.removeNthFromEnd(head, number);
  cur_node = head;
  while (cur_node) {
    std::cout << cur_node->val << ' ';
    cur_node = cur_node->next;
  }
  std::cout << std::endl;
  Delete(head);
  return 0;
}
