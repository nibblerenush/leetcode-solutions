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

class RecentCounter {
public:
  RecentCounter()
  {}

  int ping(int t) {
    while (!m_queue.empty() && t - m_queue.front() > limit) {
      m_queue.pop();
    }

    m_queue.push(t);

    return m_queue.size();
  }

private:
  queue<int> m_queue;
  const int limit = 3000;
};

int main() {
  return 0;
}
