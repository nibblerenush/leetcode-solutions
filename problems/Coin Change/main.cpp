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
  int coinChange(vector<int>& coins, int amount) {
    // queue
    queue<int> work_queue;
    work_queue.push(amount);
    
    // memorization
    unordered_map<int, int> memorization;
    
    while (!work_queue.empty()) {
      int remain = work_queue.front();
      work_queue.pop();
      
      if (remain == 0) {
        return memorization[remain];
      }
      else {
        for (int coin_value : coins) {
          if (remain - coin_value >= 0 && !memorization.count(remain - coin_value)) {
            work_queue.push(remain - coin_value);
            memorization[remain - coin_value] = memorization[remain] + 1;
          }
        }
      }
    }
    
    return -1;
  }
};

int main() {
  return 0;
}
