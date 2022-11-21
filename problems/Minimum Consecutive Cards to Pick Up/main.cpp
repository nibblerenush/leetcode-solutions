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
  int minimumCardPickup(vector<int>& cards) {
    const int n = static_cast<int>(cards.size());

    int slow = 0;
    int fast = 0;
    int result = numeric_limits<int>::max();
    unordered_set<int> usedCards;

    while (fast < n) {
      if (usedCards.count(cards[fast])) {
        while (usedCards.count(cards[fast])) {
          usedCards.erase(cards[slow]);
          ++slow;
        }

        result = min(result, fast - slow + 2);
      }

      usedCards.insert(cards[fast]);
      ++fast;
    }

    return result == numeric_limits<int>::max() ? -1 : result;
  }
};

int main() {
  return 0;
}
