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
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    
    ListNode* cur_node = head;
    ListNode* prev_node = nullptr;
    
    while (cur_node) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }

    return prev_node;
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
  head = solution.reverseList(head);
  while (head) {
    std::cout << head->val << ' ';
    head = head->next;
  }
  std::cout << std::endl;
  Delete(head);
  return 0;
}
