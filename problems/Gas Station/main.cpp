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

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int n = gas.size();
    
    int begin_index = -1;
    int remain_fuel = numeric_limits<int>::min();
    
    for (int i = 0; i < n; ++i) {
      int finish_remain_fuel = gas[i] - cost[i];
      int j = (i + 1) % n;
      int start_remain_fuel = gas[j] - cost[j];
      
      if (start_remain_fuel - finish_remain_fuel > remain_fuel) {
        remain_fuel = start_remain_fuel - finish_remain_fuel;
        begin_index = j;
      }
    }
    
    int i = begin_index;
    remain_fuel = 0;
    
    for (int count = 0; count < n; ++count) {
      remain_fuel += gas[i] - cost[i];
      
      if (remain_fuel < 0) {
        return -1;
      }
      
      i = (i + 1) % n;
    }
    
    return begin_index;
  }
};

int main() {
  return 0;
}
