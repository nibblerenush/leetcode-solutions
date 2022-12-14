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
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* cur = head;
    int idx = 1;
    
    ListNode* revHead = nullptr;
    while (idx != left) {
      revHead = cur;
      cur = cur->next;
      ++idx;
    }
    ListNode* revTail = cur;

    ListNode* prev = nullptr;
    while (idx != right + 1) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
      ++idx;
    }

    if (revHead) {
      revHead->next = prev;
    }
    else {
      head = prev;
    }
    revTail->next = cur;
    
    return head;
  }
};

int main() {
  return 0;
}
