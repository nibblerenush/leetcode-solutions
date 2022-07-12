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
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    const int nums1Size = nums1.size();
    const int nums2Size = nums2.size();
    
    struct QueueItem
    {
      int num1 = 0;
      int num2 = 0;
      int idx2 = 0;
    };
    auto compare = [](const QueueItem& lh, const QueueItem& rh)
    {
      return lh.num1 + lh.num2 > rh.num1 + rh.num2;
    };
    priority_queue<QueueItem, vector<QueueItem>, decltype(compare)> pq(compare);

    for (int i = 0; i < nums1Size; ++i)
    {
      pq.push({ nums1[i], nums2[0], 0 });
    }

    vector<vector<int>> result;

    while (k > 0 && !pq.empty())
    {
      QueueItem qi = pq.top();
      pq.pop();
      
      result.push_back({ qi.num1, qi.num2 });
      --k;

      if (qi.idx2 + 1 >= nums2Size) continue;
      pq.push({ qi.num1, nums2[qi.idx2 + 1], qi.idx2 + 1 });
    }

    return result;
  }
};

int main() {
  return 0;
}
