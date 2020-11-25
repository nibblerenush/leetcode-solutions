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

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    else if (!l2) {
      return l1;
    }

    ListNode* cur_node = nullptr;
    if (l1->val < l2->val) {
      cur_node = l1;
      l1 = l1->next;
    }
    else {
      cur_node = l2;
      l2 = l2->next;
    }

    ListNode* head = cur_node;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur_node->next = l1;
        l1 = l1->next;
      }
      else {
        cur_node->next = l2;
        l2 = l2->next;
      }
      cur_node = cur_node->next;
    }

    if (l1) {
      cur_node->next = l1;
    }
    else if (l2) {
      cur_node->next = l2;
    }

    return head;
  }
};

int main() {
  ListNode* l1 = GetLinkedList();
  ListNode* l2 = GetLinkedList();

  Solution solution;
  ListNode* head = solution.mergeTwoLists(l1, l2);
  PrintLinkedList(head);
  Delete(head);
  return 0;
}
