#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* prev_slow = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (slow) {
      while (fast && fast->val == slow->val) {
        fast = fast->next;
      }

      if (slow->next == fast) {
        prev_slow = slow;
        slow = slow->next;
      }
      else {
        if (prev_slow) {
          prev_slow->next = fast;
        }
        else {
          head = fast;
        }
        slow = fast;
      }
    }

    return head;
  }
};

int main() {
  return 0;
}
