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
  string predictPartyVictory(string senate)
  {
    const int senateLen = senate.length();

    queue<int> rq;
    queue<int> dq;
    for (int i = 0; i < senateLen; ++i)
    {
      if (senate[i] == 'R') rq.push(i);
      else dq.push(i);
    }

    while (!rq.empty() && !dq.empty())
    {
      for (int i = 0; i < senateLen; ++i)
      {
        if (senate[i] == 'R')
        {
          PopReorderQueue(dq, rq, senate);
          if (dq.empty()) break;
        }
        else if (senate[i] == 'D')
        {
          PopReorderQueue(rq, dq, senate);
          if (rq.empty()) break;
        }
      }
    }

    if (rq.empty()) return "Dire";
    return "Radiant";
  }

private:
  void PopReorderQueue(queue<int>& popq, queue<int>& reorderq, string& senate)
  {
    int idx = popq.front();
    senate[idx] = 'X';
    popq.pop();
    
    idx = reorderq.front();
    reorderq.pop();
    reorderq.push(idx);
  }
};

int main() {
  return 0;
}
