#include <iostream>
#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head && head->next) {
      ListNode* cur_tail = swapPairs(head->next->next);
      ListNode* cur_head = head->next;
      head->next->next = head;
      head->next = cur_tail;
      return cur_head;
    }
    else {
      return head;
    }
  }
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

ListNode* GetLinkedList() {
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

  return head;
}

int main() {
  ListNode* head = GetLinkedList();

  Solution solution;
  head = solution.swapPairs(head);
  PrintLinkedList(head);

  Delete(head);
  return 0;
}
