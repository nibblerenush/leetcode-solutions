#include <cassert>
#include <iostream>

class MyLinkedList {
private:
  struct Node {
    int val = 0;
    Node* next = nullptr;
  };

public:
  ~MyLinkedList() {
    Node* cur_node = m_head;

    while (cur_node) {
      Node* prev_node = cur_node;
      cur_node = cur_node->next;
      delete prev_node;
    }
  }
  
  int get(int index) {
    if (!checkCorrectIndex(index)) {
      return -1;
    }
    return getNodeByIndex(index)->val;
  }
  
  void addAtHead(int val) {
    Node* new_node = new Node{ val, m_head };
    m_head = new_node;
    
    if (!m_tail) {
      m_tail = m_head;
    }

    ++m_size;
  }

  void addAtTail(int val) {
    if (m_tail) {
      m_tail->next = new Node{ val };
      m_tail = m_tail->next;
    }
    else {
      m_head = m_tail = new Node{ val };
    }

    ++m_size;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > m_size) {
      return;
    }

    if (index == 0) {
      addAtHead(val);
    }
    else if (index == m_size) {
      addAtTail(val);
    }
    else {
      auto prev_node = getNodeByIndex(index - 1);
      Node* new_node = new Node{ val, prev_node->next };
      prev_node->next = new_node;
      ++m_size;
    }
  }

  void deleteAtIndex(int index) {
    if (!checkCorrectIndex(index)) {
      return;
    }
    
    if (index == 0) {
      Node* old_head = m_head;
      m_head = m_head->next;
      delete old_head;

      if (!m_head) {
        m_tail = nullptr;
      }
    }
    else {
      auto prev_node = getNodeByIndex(index - 1);
      Node* cur_node = prev_node->next;
      prev_node->next = cur_node->next;
      delete cur_node;
      
      if (index == m_size - 1) {
        m_tail = prev_node;
      }
    }

    --m_size;
  }

  int getSize() {
    return m_size;
  }

private:
  Node* getNodeByIndex(int index) const {
    Node* cur_node = m_head;
    Node* prev_node = nullptr;
    int cur_index = -1;
    
    while (cur_index != index) {
      ++cur_index;
      prev_node = cur_node;
      cur_node = cur_node->next;
    }

    return prev_node;
  }
  
  bool checkCorrectIndex(int index) const {
    return m_size != 0 && index >= 0 && index < m_size;
  }

private:
  Node* m_head = nullptr;
  Node* m_tail = nullptr;
  int m_size = 0;
};

int main() {
  MyLinkedList linked_list;
  
  linked_list.addAtHead(2);
  linked_list.addAtHead(1);
  linked_list.addAtTail(3);
  linked_list.addAtTail(4);

  assert(linked_list.getSize() == 4);
  assert(linked_list.get(0) == 1);
  assert(linked_list.get(1) == 2);
  assert(linked_list.get(2) == 3);
  assert(linked_list.get(3) == 4);

  linked_list.deleteAtIndex(0);
  linked_list.deleteAtIndex(0);
  linked_list.deleteAtIndex(0);
  linked_list.deleteAtIndex(0);

  assert(linked_list.getSize() == 0);
  assert(linked_list.get(0) == -1);

  linked_list.addAtIndex(0, 5);
  linked_list.addAtIndex(1, 6);
  linked_list.addAtIndex(1, 7);
  linked_list.addAtIndex(7, 8);
  linked_list.deleteAtIndex(7);
  linked_list.addAtTail(9);

  assert(linked_list.getSize() == 4);
  assert(linked_list.get(0) == 5);
  assert(linked_list.get(1) == 7);
  assert(linked_list.get(2) == 6);
  assert(linked_list.get(3) == 9);
  
  for (int i = 0; i < linked_list.getSize(); ++i) {
    std::cout << i << ' ' << linked_list.get(i) << std::endl;
  }

  return 0;
}
