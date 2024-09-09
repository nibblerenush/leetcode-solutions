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
    int i = 1;
    ListNode* leftNode = head;
    ListNode* prevLeftNode = nullptr;
    while (i != left)
    {
      prevLeftNode = leftNode;
      leftNode = leftNode->next;
      ++i;
    }
    
    ListNode* node = leftNode;
    ListNode* prevNode = nullptr;
    while (i != right + 1)
    {
      ListNode* nextNode = node->next;
      node->next = prevNode;
      prevNode = node;
      node = nextNode;
      ++i;
    }

    if (prevLeftNode)
    {
      prevLeftNode->next = prevNode;
    }
    else
    {
      head = prevNode;
    }
    leftNode->next = node;

    return head;
  }
};

int main() {
  return 0;
}
