#include <cassert>
#include <iostream>
#include <queue>

class MyStack {
public:
  void push(int x) {
    if (m_q1.empty()) {
      queueMove(m_q1, m_q2, x);
    }
    else {
      queueMove(m_q2, m_q1, x);
    }
  }

  int pop() {
    int result = 0;

    if (!m_q1.empty()) {
      result = m_q1.front();
      m_q1.pop();
    }
    else {
      result = m_q2.front();
      m_q2.pop();
    }

    return result;
  }

  int top() {
    return !m_q1.empty() ? m_q1.front() : m_q2.front();
  }

  bool empty() {
    return m_q1.empty() && m_q2.empty();
  }

private:
  void queueMove(std::queue<int>& q1, std::queue<int>& q2, int x) {
    q1.push(x);
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

private:
  std::queue<int> m_q1;
  std::queue<int> m_q2;
};

int main() {
  MyStack myStack;

  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  assert(myStack.pop() == 3);
  assert(myStack.pop() == 2);
  assert(myStack.pop() == 1);
  assert(myStack.empty());

  myStack.push(4);
  myStack.push(5);
  assert(myStack.top() == 5);
  assert(myStack.pop() == 5);
  myStack.push(6);
  assert(myStack.top() == 6);
  assert(myStack.pop() == 6);
  assert(myStack.top() == 4);
  assert(myStack.pop() == 4);

  return 0;
}
