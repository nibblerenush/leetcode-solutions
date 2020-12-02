#include <cassert>
#include <iostream>
#include <stack>

class MyQueue {
public:
  void push(int x) {
    back.push(x);
  }

  int pop() {
    moveFromBack();
    int result = front.top();
    front.pop();
    return result;
  }

  int peek() {
    moveFromBack();
    return front.top();
  }

  bool empty() {
    return front.empty() && back.empty();
  }

private:
  void moveFromBack() {
    if (front.empty()) {
      while (!back.empty()) {
        front.push(back.top());
        back.pop();
      }
    }
  }

private:
  std::stack<int> front;
  std::stack<int> back;
};

int main() {
  MyQueue myQueue;

  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  assert(myQueue.pop() == 1);
  assert(myQueue.pop() == 2);
  assert(myQueue.pop() == 3);
  assert(myQueue.empty());

  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  assert(myQueue.pop() == 1);
  assert(myQueue.pop() == 2);
  assert(!myQueue.empty());
  myQueue.push(4);
  myQueue.push(5);
  assert(myQueue.pop() == 3);
  assert(myQueue.pop() == 4);
  assert(myQueue.pop() == 5);

  return 0;
}
