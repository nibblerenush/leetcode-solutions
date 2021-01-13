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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* right_node = head;
    for (int i = 0; i < n; ++i) {
      right_node = right_node->next;
    }
    
    ListNode* cur_node = head;
    ListNode* prev_node = nullptr;
    while (right_node) {
      prev_node = cur_node;
      cur_node = cur_node->next;
      right_node = right_node->next;
    }
    
    if (prev_node) {
      prev_node->next = cur_node->next;
    }
    else {
      head = cur_node->next;
    }

    delete cur_node;
    return head;
  }
};

int main() {
  return 0;
}
