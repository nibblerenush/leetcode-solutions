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

class Solution {
public:
  int nthUglyNumber(int n) {
    const vector<int> multipliers = { 2, 3, 5 };
    
    priority_queue<int, vector<int>, greater<int>> workQueue;
    unordered_set<int> usedNums;
    
    int i = 0;
    workQueue.push(1);
    usedNums.insert(1);
    
    int uglyNumber = 0;
    while (i != n) {
      uglyNumber = workQueue.top();
      workQueue.pop();
      ++i;
      
      for (int multiplier : multipliers) {
        long int newNum = static_cast<long int>(uglyNumber) * multiplier;
        if (newNum <= numeric_limits<int>::max() && !usedNums.count(newNum)) {
          workQueue.push(newNum);
          usedNums.insert(newNum);
        }
      }
    }
    
    return uglyNumber;
  }
};

int main() {
  return 0;
}
