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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    
    while (curA != curB) {
      curA = curA ? curA->next : headB;
      curB = curB ? curB->next : headA;
    }
    
    return curA;
  }
};

int main() {
  return 0;
}
