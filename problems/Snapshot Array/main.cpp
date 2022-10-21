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

class SnapshotArray {
public:
  SnapshotArray(int length)
    : m_currentSnapId(0)
    , m_snapshotVector(length)
  {}
  
  void set(int index, int val) {
    m_snapshotVector[index][m_currentSnapId] = val;
  }
  
  int snap() {
    ++m_currentSnapId;
    return m_currentSnapId - 1;
  }
  
  int get(int index, int snap_id) {
    const map<int, int>& snapshotVal = m_snapshotVector[index];
    if (snapshotVal.empty()) {
      return 0;
    }
    
    auto iter = snapshotVal.upper_bound(snap_id);
    if (iter == snapshotVal.begin()) {
      return 0;
    }
    return prev(iter)->second;
  }

private:
  int m_currentSnapId = 0;
  vector<map<int, int>> m_snapshotVector;
};

int main() {
  return 0;
}
