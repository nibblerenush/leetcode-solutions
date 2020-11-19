#include <iostream>

class MyLinkedList {
private:
  struct Node {
    int val = 0;
    Node* next = nullptr;
  };

  Node* m_head;
  Node* m_tail;
  int m_size;

public:
  MyLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0)
  {}

  ~MyLinkedList() {
    Node* cur_node = m_head;

    while (cur_node) {
      Node* prev_node = cur_node;
      cur_node = cur_node->next;
      delete prev_node;
    }
  }

  int get(int index) {
    if (index < 0) {
      return -1;
    }
    
    Node* cur_node = m_head;
    int cur_index = -1;
    int result = -1;
    
    while (cur_node && cur_index != index) {
      ++cur_index;
      result = cur_node->val;
      cur_node = cur_node->next;
    }

    return cur_index == index ? result : -1;
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
      Node* cur_node = m_head;
      Node* prev_node = nullptr;
      int cur_index = -1;

      while (cur_index != index - 1) {
        ++cur_index;
        prev_node = cur_node;
        cur_node = cur_node->next;
      }

      Node* new_node = new Node{ val, cur_node };
      prev_node->next = new_node;

      ++m_size;
    }
  }

  void deleteAtIndex(int index) {
    if (m_size == 0 || index < 0 || index >= m_size) {
      return;
    }

    if (index == 0) {
      Node* old_head = m_head;
      m_head = m_head->next;
      delete old_head;
      --m_size;
    }
    else {
      Node* cur_node = m_head;
      Node* prev_node = nullptr;
      int cur_index = -1;

      while (cur_index != index - 1) {
        ++cur_index;
        prev_node = cur_node;
        cur_node = cur_node->next;
      }

      prev_node->next = cur_node->next;
      delete cur_node;

      if (index == m_size - 1) {
        m_tail = prev_node;
      }

      --m_size;
    }
  }

  int getSize() {
    return m_size;
  }
};

int main() {
  MyLinkedList linked_list;
  linked_list.addAtHead(1);
  linked_list.addAtHead(2);
  linked_list.addAtTail(3);
  linked_list.addAtTail(4);

  linked_list.addAtIndex(0, 5);
  linked_list.addAtIndex(1, 6);
  linked_list.addAtIndex(1, 7);
  linked_list.addAtIndex(7, 8);

  linked_list.deleteAtIndex(7);
  linked_list.addAtTail(9);
  
  for (int i = 0; i < linked_list.getSize(); ++i) {
    std::cout << i << ' ' << linked_list.get(i) << std::endl;
  }

  return 0;
}
