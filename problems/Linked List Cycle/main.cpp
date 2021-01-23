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
      fast_runner = fast_runner->next ? fast_runner->next->next : nullptr;
    }
    
    return false;
  }
};

int main() {
  return 0;
}
