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
  string countAndSay(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
      result = get_next_count_and_say(result);
    }

    return result;
  }

private:
  string get_next_count_and_say(const string& count_and_say) {
    // Init
    int i = 0;
    int j = 1;
    string result;
    
    // Main algorithm
    while (j < (int)count_and_say.length()) {
      if (count_and_say[j] != count_and_say[i]) {
        result.push_back(j - i + '0');
        result.push_back(count_and_say[i]);
        i = j;
      }
      j += 1;
    }

    // Post processing
    result.push_back(j - i + '0');
    result.push_back(count_and_say[i]);

    return result;
  }
};

int main() {
  return 0;
}
