#include <iostream>
#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
      return nullptr;
    }
    
    ListNode* cur_node = head;
    int list_size = 0;
    while (cur_node) {
      ++list_size;
      cur_node = cur_node->next;
    }
    
    k = k % list_size;
    
    cur_node = head;
    ListNode* prev_node = nullptr;
    while (cur_node) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }

    cur_node = prev_node;
    prev_node = nullptr;

    for (int i = 0; i < k; ++i) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }

    ListNode* left_part = prev_node;
    prev_node = nullptr;

    for (int i = 0; i < list_size - k; ++i) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }

    ListNode* right_part = prev_node;
    prev_node = nullptr;

    cur_node = left_part;
    while (cur_node) {
      prev_node = cur_node;
      cur_node = cur_node->next;
    }

    ListNode* result = nullptr;
    if (prev_node) {
      prev_node->next = right_part;
      result = left_part;
    }
    else {
      result = right_part;
    }
    return result;
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
  int k = 0;
  std::cin >> k;
  ListNode* head = GetLinkedList();

  Solution solution;
  head = solution.rotateRight(head, k);
  PrintLinkedList(head);
  Delete(head);
  return 0;
}
