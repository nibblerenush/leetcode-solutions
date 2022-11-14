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

class ExamRoom {
public:
  ExamRoom(int n) : m_roomSize(n)
  {}

  int seat() {
    if (m_occupiedSeats.empty()) {
      m_occupiedSeats.insert(0);
      return 0;
    }
    
    int maxDistance = abs(0 - *m_occupiedSeats.begin());
    int seat = 0;
    
    if (m_occupiedSeats.count(0)) {
      maxDistance /= 2;
      seat = maxDistance;
    }
    
    for (auto iter = m_occupiedSeats.begin(); iter != prev(m_occupiedSeats.end()); ++iter) {
      int distance = abs(*iter - *next(iter)) / 2;
      if (distance > maxDistance) {
        seat = *iter + distance;
        maxDistance = distance;
      }
    }
    
    int distance = abs(*prev(m_occupiedSeats.end()) - (m_roomSize - 1));
    if (m_occupiedSeats.count(m_roomSize - 1)) {
      distance /= 2;
    }
    
    if (distance > maxDistance) {
      if (m_occupiedSeats.count(m_roomSize - 1)) {
        seat = *prev(m_occupiedSeats.end()) + distance;
      }
      else {
        seat = m_roomSize - 1;
      }
    }
    
    m_occupiedSeats.insert(seat);
    return seat;
  }

  void leave(int p) {
    m_occupiedSeats.erase(p);
  }

private:
  int m_roomSize;
  set<int> m_occupiedSeats;
};

int main() {
  return 0;
}
