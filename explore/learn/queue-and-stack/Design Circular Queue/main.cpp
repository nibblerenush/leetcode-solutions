#include <cassert>
#include <iostream>
#include <vector>

class MyCircularQueue {
public:
  MyCircularQueue(int k) : m_queue(k)
  {}

  bool enQueue(int value) {
    if (isEmpty()) {
      m_head = 0;
      m_tail = 0;
      m_queue[m_tail] = value;
      return true;
    }
    
    if (!isFull()) {
      m_tail = iterate(m_tail);
      m_queue[m_tail] = value;
      return true;
    }
    
    return false;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    
    if (m_head == m_tail) {
      m_head = -1;
      m_tail = -1;
    }
    else {
      m_head = iterate(m_head);
    }
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return m_queue[m_head];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return m_queue[m_tail];
  }
  
  bool isEmpty() {
    return m_head == -1 && m_tail == -1;
  }

  bool isFull() {
    return m_head != -1 && m_tail != -1 && iterate(m_tail) == m_head;
  }

private:
  int iterate(int index) {
    return (index + 1) % static_cast<int>(m_queue.size());
  }

private:
  std::vector<int> m_queue;
  int m_head = -1;
  int m_tail = -1;
};

int main() {
  MyCircularQueue queue(5);

  assert(queue.Front() == -1);
  assert(queue.Rear() == -1);
  assert(queue.enQueue(1));
  assert(queue.enQueue(2));
  assert(queue.enQueue(3));
  assert(queue.Front() == 1);
  assert(queue.Rear() == 3);
  assert(queue.enQueue(4));
  assert(queue.enQueue(5));
  assert(!queue.enQueue(6));
  assert(queue.deQueue());
  assert(queue.deQueue());
  assert(queue.deQueue());
  assert(queue.deQueue());
  assert(queue.deQueue());
  assert(!queue.deQueue());

  return 0;
}
