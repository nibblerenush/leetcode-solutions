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
    int result = 0;
    int min_price = prices[0];
    
    for (int i = 1; i < (int)prices.size(); ++i) {
      int profit = prices[i] - min_price;
      result = max(result, profit);
      min_price = min(min_price, prices[i]);
    }

    return result;
  }
};

int main() {
  return 0;
}
