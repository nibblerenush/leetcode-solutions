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
  string getSmallestString(int n, int k) {
    string result(n, 'a');
    
    k -= n;
    int i = result.size() - 1;
    
    while (k > 0) {
      if (result[i] >= 'z') {
        i -= 1;
      }
      result[i] += 1;
      k -= 1;
    }
    
    return result;
  }
};

int main() {
  return 0;
}
