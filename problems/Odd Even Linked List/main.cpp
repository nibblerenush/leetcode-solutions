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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode* cur_odd = head, * odd_head = head;
    ListNode* cur_even = nullptr, * even_head = nullptr;
    ListNode* prev_odd = nullptr;
    
    while (cur_odd && cur_odd->next) {
      if (cur_even) {
        cur_even->next = cur_odd->next;
        cur_even = cur_even->next;
      }
      else {
        cur_even = cur_odd->next;
        even_head = cur_even;
      }
      
      prev_odd = cur_odd;
      cur_odd->next = cur_even->next;
      cur_odd = cur_odd->next;
    }

    if (cur_even) {
      cur_even->next = nullptr;
    }

    if (cur_odd) {
      cur_odd->next = even_head;
    }
    else if (prev_odd) {
      prev_odd->next = even_head;
    }

    return head;
  }
};

int main() {
  return 0;
}
