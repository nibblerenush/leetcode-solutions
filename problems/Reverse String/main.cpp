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
  void reverseString(vector<char>& s) {
    int i = 0;
    int j = static_cast<int>(s.size()) - 1;

    while (i < j) {
      swap(s[i++], s[j--]);
    }
  }
};

int main() {
  return 0;
}
