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
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    const int barcodesSize = barcodes.size();

    unordered_map<int, int> barcodeCount;
    for (int barcode : barcodes)
    {
      ++barcodeCount[barcode];
    }

    priority_queue<pair<int, int>> pq;
    for (const auto& item : barcodeCount)
    {
      pq.push({ item.second, item.first });
    }

    vector<int> result;
    while (!pq.empty())
    {
      pair<int, int> top = pq.top();
      pq.pop();
      
      if (result.empty() || result.back() != top.second)
      {
        result.push_back(top.second);
        --top.first;
        if (top.first != 0)
        {
          pq.push(top);
        }
      }
      else
      {
        pair<int, int> postTop = pq.top();
        pq.pop();

        result.push_back(postTop.second);
        --postTop.first;
        if (postTop.first != 0)
        {
          pq.push(postTop);
        }
        pq.push(top);
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
