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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur_node = nullptr;
    ListNode* head = nullptr;

    int temp = 0;
    while (l1 && l2) {
      int val = (l1->val + l2->val + temp) % 10;
      if (!head) {
        head = new ListNode(val);
        cur_node = head;
      }
      else {
        cur_node->next = new ListNode(val);
        cur_node = cur_node->next;
      }
      temp = (l1->val + l2->val + temp) / 10;

      l1 = l1->next;
      l2 = l2->next;
    }

    computeTail(cur_node, l1, temp);
    computeTail(cur_node, l2, temp);

    if (temp) {
      cur_node->next = new ListNode(1);
    }

    return head;
  }

private:
  void computeTail(ListNode*& cur_node, ListNode* l, int& temp) {
    while (l) {
      int val = (l->val + temp) % 10;
      cur_node->next = new ListNode(val);
      cur_node = cur_node->next;
      temp = (l->val + temp) / 10;
      l = l->next;
    }
  }
};

int main() {
  ListNode* l1 = GetLinkedList();
  ListNode* l2 = GetLinkedList();

  Solution solution;
  ListNode* head = solution.addTwoNumbers(l1, l2);
  PrintLinkedList(head);

  Delete(l1);
  Delete(l2);
  Delete(head);
  return 0;
}
