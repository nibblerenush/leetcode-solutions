#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* h1 = nullptr;
    ListNode* cur1 = nullptr;

    ListNode* h2 = nullptr;
    ListNode* cur2 = nullptr;

    while (head) {
      if (head->val < x) {
        if (h1) {
          cur1->next = head;
          cur1 = cur1->next;
        }
        else {
          h1 = head;
          cur1 = h1;
        }
      }
      else {
        if (h2) {
          cur2->next = head;
          cur2 = cur2->next;
        }
        else {
          h2 = head;
          cur2 = h2;
        }
      }
      head = head->next;
    }

    if (cur1) {
      cur1->next = nullptr;
    }
    if (cur2) {
      cur2->next = nullptr;
    }

    if (h1) {
      cur1 = h1;
      ListNode* prevCur1 = nullptr;
      while (cur1) {
        prevCur1 = cur1;
        cur1 = cur1->next;
      }
      prevCur1->next = h2;
      return h1;
    }
    return h2;
  }
};

int main() {
  return 0;
}
