#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
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

class LRUCache {
public:
  LRUCache(int capacity) : m_cur_capacity(0), m_capacity(capacity)
  {}
  
  int get(int key) {
    if (m_key_iter.count(key)) {
      list<pair<int, int>>::iterator iter = m_key_iter[key];
      m_key_value.splice(m_key_value.begin(), m_key_value, iter);
      return iter->second;
    }
    
    return -1;
  }

  void put(int key, int value) {
    if (m_key_iter.count(key)) {
      list<pair<int, int>>::iterator iter = m_key_iter[key];
      m_key_value.splice(m_key_value.begin(), m_key_value, iter);
      iter->second = value;
    }
    else {
      if (m_cur_capacity == m_capacity) {
        m_key_iter.erase(m_key_value.back().first);
        m_key_value.pop_back();
      }
      else {
        m_cur_capacity += 1;
      }
      
      m_key_value.push_front({ key, value });
      m_key_iter[key] = m_key_value.begin();
    }
  }

private:
  int m_cur_capacity;
  const int m_capacity;
  
  list<pair<int, int>> m_key_value;
  unordered_map<int, list<pair<int, int>>::iterator> m_key_iter;
};

int main() {
  return 0;
}
