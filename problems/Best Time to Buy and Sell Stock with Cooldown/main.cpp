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
    const int size = prices.size();
    if (size == 0) {
      return 0;
    }
    
    int result = 0;
    vector<int> dynamic(size);
    dynamic[0] = 0;
    
    for (int i = 1; i < size; ++i) {
      int profit = 0;
      for (int j = i - 1; j >= 0; --j) {
        int temp = prices[i] - prices[j];
        if (j - 2 >= 0) {
          temp += dynamic[j - 2];
        }
        profit = max(profit, temp);
      }
      
      dynamic[i] = max(profit, dynamic[i - 1]);
      result = max(result, dynamic[i]);
    }
    
    return result;
  }
};

int main() {
  return 0;
}
