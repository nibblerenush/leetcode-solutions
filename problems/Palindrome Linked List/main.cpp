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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
      return true;
    }
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* prev_node = !fast ? slow : nullptr;
    ListNode* cur_node = slow->next;
    slow->next = nullptr;
    
    while (cur_node) {
      ListNode* next_node = cur_node->next;
      cur_node->next = prev_node;
      prev_node = cur_node;
      cur_node = next_node;
    }
    
    while (head && prev_node) {
      if (head->val != prev_node->val) {
        return false;
      }
      
      head = head->next;
      prev_node = prev_node->next;
    }

    return true;
  }
};

int main() {
  return 0;
}
