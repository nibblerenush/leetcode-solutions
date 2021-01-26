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

class MedianFinder {
public:
  MedianFinder() : m_size(0), m_cur_median(0.0)
  {}
  
  void addNum(int num) {
    m_set.insert(num);
    
    if (m_size == 0) {
      m_center = m_set.begin();
      m_cur_median = *m_center;
      m_size = m_set.size();
      return;
    }
    
    if (m_size % 2 != 0) {
      if (num >= (int)m_cur_median) {
        m_left = m_center;
        m_right = next(m_left);
      }
      else {
        m_right = m_center;
        m_left = prev(m_right);
      }
      m_cur_median = ((double)*m_right + *m_left) / 2;
    }
    else {
      if (num >= *m_right) {
        m_center = m_right;
      }
      else if (num < *m_left) {
        m_center = m_left;
      }
      // *m_left <= num < *m_right
      else {
        m_center = next(m_left);
      }
      m_cur_median = *m_center;
    }
    
    m_size = m_set.size();
  }
  
  double findMedian() {
    return m_cur_median;
  }

private:
  multiset<int> m_set;
  int m_size;
  
  multiset<int>::iterator m_left;
  multiset<int>::iterator m_right;
  multiset<int>::iterator m_center;
  
  double m_cur_median;
};

int main() {
  return 0;
}
