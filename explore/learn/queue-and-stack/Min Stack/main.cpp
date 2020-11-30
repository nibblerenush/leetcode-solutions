#include <cassert>
#include <iostream>
#include <stack>

class MinStack {
public:
  void push(int x) {
    elems.push(x);
    if (min_elems.empty() || x <= min_elems.top()) {
      min_elems.push(x);
    }
    else {
      min_elems.push(min_elems.top());
    }
  }

  void pop() {
    elems.pop();
    min_elems.pop();
  }

  int top() {
    return elems.top();
  }

  int getMin() {
    return min_elems.top();
  }

private:
  std::stack<int> elems;
  std::stack<int> min_elems;
};

int main() {
  MinStack minStack;

  minStack.push(1);
  minStack.push(2);
  minStack.push(3);
  assert(minStack.top() == 3);
  assert(minStack.getMin() == 1);

  minStack.pop();
  minStack.pop();
  minStack.pop();
  minStack.push(3);
  minStack.push(2);
  minStack.push(1);
  assert(minStack.top() == 1);
  assert(minStack.getMin() == 1);

  minStack.pop();
  assert(minStack.top() == 2);
  assert(minStack.getMin() == 2);

  return 0;
}
