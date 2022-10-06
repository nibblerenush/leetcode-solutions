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

class TimeMap {
public:
  TimeMap()
  {}
  
  void set(string key, string value, int timestamp) {
    m_timeMap[key][timestamp] = value;
  }
  
  string get(string key, int timestamp) {
    const map<int, string>& keyTimes = m_timeMap[key];
    
    if (keyTimes.empty()) {
      return "";
    }

    auto iter = keyTimes.upper_bound(timestamp);
    if (iter == keyTimes.begin()) {
      return "";
    }

    return (--iter)->second;
  }

private:
  unordered_map<string, map<int, string>> m_timeMap;
};

int main() {
  return 0;
}
