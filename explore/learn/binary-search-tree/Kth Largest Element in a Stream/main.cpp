#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) : m_size(0), m_k(k) {
    for (int num : nums) {
      add(num);
    }
  }

  int add(int val) {
    ++m_tree[val];
    ++m_size;

    if (m_size > m_k) {
      --m_tree.begin()->second;
      if (m_tree.begin()->second == 0) {
        m_tree.erase(m_tree.begin());
      }
    }

    return m_tree.begin()->first;
  }

private:
  map<int, int> m_tree;
  int m_size;
  int m_k;
};

int main() {
  return 0;
}
