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
  int hIndex(vector<int>& citations) {
    int result = 0;
    sort(citations.begin(), citations.end());
    const int size = citations.size();
    
    for (int i = 0; i < size; ++i) {
      result = max(result, min(citations[i], size - i));
    }

    return result;
  }
};

int main() {
  return 0;
}
