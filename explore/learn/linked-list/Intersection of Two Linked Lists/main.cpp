#include <cmath>
#include <iostream>
#include <utility>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

void Delete(ListNode* head) {
  while (head) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* longList = nullptr;
    ListNode* shortList = nullptr;

    int sizeA = calcSize(headA);
    int sizeB = calcSize(headB);
    int diffSize = std::abs(sizeA - sizeB);
    
    if (sizeA > sizeB) {
      longList = headA;
      shortList = headB;
    }
    else {
      longList = headB;
      shortList = headA;
    }

    for (int i = 0; i < diffSize; ++i) {
      longList = longList->next;
    }

    while (longList && shortList) {
      if (longList == shortList) {
        return longList;
      }

      longList = longList->next;
      shortList = shortList->next;
    }
    return nullptr;
  }

private:
  int calcSize(ListNode* head) {
    int size = 0;
    while (head) {
      ++size;
      head = head->next;
    }
    return size;
  };
};

ListNode* GetList() {
  int n = 0;
  std::cin >> n;

  ListNode* head = nullptr;
  ListNode* cur_node = nullptr;

  for (int i = 0; i < n; ++i) {
    int val = 0;
    std::cin >> val;
    ListNode* new_node = new ListNode{ val };

    if (cur_node) {
      cur_node->next = new_node;
      cur_node = cur_node->next;
    }
    else {
      cur_node = new_node;
      head = cur_node;
    }
  }

  return head;
}

int main() {
  ListNode* headA = GetList();
  ListNode* headB = GetList();

  Solution solution;
  ListNode* result = solution.getIntersectionNode(headA, headB);
  if (result) {
    std::cout << result << ": " << result->val;
  }
  else {
    std::cout << "null";
  }
  std::cout << std::endl;
  Delete(headA);
  Delete(headB);
  return 0;
}
