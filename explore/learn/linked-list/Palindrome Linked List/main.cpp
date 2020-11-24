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
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true;
    }
    
    int list_size = 0;
    ListNode* cur_node = head;
    while (cur_node) {
      ++list_size;
      cur_node = cur_node->next;
    }
    int middle_idx = list_size % 2 == 0 ? list_size / 2 : list_size / 2 + 1;

    cur_node = head;
    ListNode* prev_node = nullptr;
    for (int i = 0; i < middle_idx; ++i) {
      prev_node = cur_node;
      cur_node = cur_node->next;
    }
    
    if (prev_node) {
      prev_node->next = nullptr;
    }

    prev_node = nullptr;
    while (cur_node) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }
    ListNode* second_head = prev_node;

    while (second_head && head) {
      if (second_head->val != head->val) {
        return false;
      }
      second_head = second_head->next;
      head = head->next;
    }
    return true;
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
  std::cout << std::boolalpha << solution.isPalindrome(head) << std::endl;
  Delete(head);
  return 0;
}
