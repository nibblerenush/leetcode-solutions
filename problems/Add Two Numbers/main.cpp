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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = nullptr;
    ListNode* cur_node = nullptr;
    
    int temp = 0;
    while (l1 && l2) {
      int sum = l1->val + l2->val + temp;
      
      int val = sum % 10;
      if (!result) {
        result = new ListNode(val);
        cur_node = result;
      }
      else {
        cur_node->next = new ListNode(val);
        cur_node = cur_node->next;
      }
      temp = sum / 10;
      
      l1 = l1->next;
      l2 = l2->next;
    }
    
    computeTail(cur_node, l1, temp);
    computeTail(cur_node, l2, temp);
    
    if (temp) {
      cur_node->next = new ListNode(temp);
    }
    
    return result;
  }

private:
  void computeTail(ListNode*& cur_node, ListNode* l, int& temp) {
    while (l) {
      int sum = l->val + temp;
      
      int val = sum % 10;
      cur_node->next = new ListNode(val);
      cur_node = cur_node->next;
      temp = sum / 10;
      
      l = l->next;
    }
  }
};

int main() {
  return 0;
}
