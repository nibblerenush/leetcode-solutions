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

class MinStack {
public:
  void push(int x) {
    m_elems.push(x);
    if (m_min_elems.empty() || x <= m_min_elems.top()) {
      m_min_elems.push(x);
    }
    else {
      m_min_elems.push(m_min_elems.top());
    }
  }
  
  void pop() {
    m_elems.pop();
    m_min_elems.pop();
  }
  
  int top() {
    return m_elems.top();
  }
  
  int getMin() {
    return m_min_elems.top();
  }

private:
  stack<int> m_elems;
  stack<int> m_min_elems;
};

int main() {
  return 0;
}
