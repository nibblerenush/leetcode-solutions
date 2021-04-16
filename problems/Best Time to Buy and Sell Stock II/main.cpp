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
  int maxProfit(vector<int>& prices) {
    // Init
    int result = 0;
    int max_profit = 0;
    int min_price = prices[0];
    
    for (int i = 1; i < (int)prices.size(); ++i) {
      int cur_profit = prices[i] - min_price;
      
      if (cur_profit > max_profit) {
        max_profit = cur_profit;
      }
      else {
        result += max_profit;
        max_profit = 0;
        min_price = prices[i];
      }
      
      min_price = min(min_price, prices[i]);
    }

    // Post processing
    result += max_profit;
    return result;
  }
};

int main() {
  return 0;
}
