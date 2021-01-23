#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* slow_next = slow->next;
    slow->next = nullptr;
    
    return merge(sortList(head), sortList(slow_next));
  }

private:
  ListNode* merge(ListNode* l1, ListNode* l2) {
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
    
    ListNode* result_head = cur_node;
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
    
    return result_head;
  }
};

int main() {
  return 0;
}
