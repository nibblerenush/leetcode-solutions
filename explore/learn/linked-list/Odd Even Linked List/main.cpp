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

void PrintLinkedList(ListNode* head) {
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode* cur_odd = head, * odd_head = head;
    ListNode* cur_even = nullptr, * even_head = nullptr;
    ListNode* prev_odd = nullptr;
    
    while (cur_odd && cur_odd->next) {
      if (cur_even) {
        cur_even->next = cur_odd->next;
        cur_even = cur_even->next;
      }
      else {
        cur_even = cur_odd->next;
        even_head = cur_even;
      }
      
      prev_odd = cur_odd;
      cur_odd->next = cur_even->next;
      cur_odd = cur_odd->next;
    }

    if (cur_even) {
      cur_even->next = nullptr;
    }

    if (cur_odd) {
      cur_odd->next = even_head;
    }
    else if (prev_odd) {
      prev_odd->next = even_head;
    }

    return head;
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  
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
  head = solution.oddEvenList(head);
  PrintLinkedList(head);
  Delete(head);
  return 0;
}
