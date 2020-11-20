#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
      return false;
    }

    ListNode* slow_runner = head;
    ListNode* fast_runner = head->next;

    while (slow_runner && fast_runner) {
      if (slow_runner == fast_runner) {
        return true;
      }

      slow_runner = slow_runner->next;
      if (fast_runner->next) {
        fast_runner = fast_runner->next->next;
      }
      else {
        fast_runner = fast_runner->next;
      }
    }

    return false;
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
  std::cout << std::boolalpha << solution.hasCycle(head) << std::endl;
  return 0;
}
