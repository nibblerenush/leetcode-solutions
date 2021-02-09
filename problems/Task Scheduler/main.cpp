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
  int leastInterval(vector<char>& tasks, int n) {
    // prepare
    const int size = 26;
    vector<int> task_count(size, 0);
    for (char task : tasks) {
      task_count[task - 'A'] += 1;
    }
    
    // sort count order
    sort(task_count.begin(), task_count.end());
    
    // free spaces between most freq task
    int gap = (task_count[size - 1] - 1) * n;
    
    // free spaces + most freq task count
    int result = gap + task_count[size - 1];
    
    for (int i = size - 2; i >= 0 && task_count[i] != 0; --i) {
      // has free spaces
      if (task_count[i] <= gap) {
        // most freq task
        if (task_count[i] == task_count[size - 1]) {
          result += 1;
          gap -= (task_count[size - 1] - 1);
        }
        // common task
        else {
          gap -= task_count[i];
        }
      }
      else {
        return tasks.size();
      }
    }
    
    return result;
  }
};

int main() {
  return 0;
}
