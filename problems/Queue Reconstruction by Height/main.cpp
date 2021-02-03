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
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // size_t to int
    const int size = people.size();
    
    // init result
    vector<vector<int>> result(size);
    for (int i = 0; i < size; ++i) {
      result[i] = { numeric_limits<int>::max(), i };
    }
    
    // sort people
    sort(people.begin(), people.end());
    
    for (const auto& man : people) {
      int h = man[0];
      int k = man[1];
      
      int j = 0;
      int count = 0;
      while (count != k || result[j][0] != numeric_limits<int>::max()) {
        if (result[j][0] >= h) {
          count += 1;
        }
        
        j += 1;
      }
      
      result[j] = man;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
