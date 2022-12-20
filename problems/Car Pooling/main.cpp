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
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    // trip[0] - numPassengers
    // trip[1] - from
    // trip[2] - to

    struct {
      bool operator() (const vector<int>& lh, const vector<int>& rh) {
        return lh[1] < rh[1];
      }
    } compFrom;
    sort(trips.begin(), trips.end(), compFrom);
    
    struct {
      bool operator() (const vector<int>& lh, const vector<int>& rh) {
        return lh[2] > rh[2];
      }
    } compTo;
    priority_queue<vector<int>, vector<vector<int>>, decltype(compTo)> pq;
    
    for (const vector<int>& trip : trips) {
      while (!pq.empty() && pq.top()[2] <= trip[1]) {
        capacity += pq.top()[0];
        pq.pop();
      }

      pq.push(trip);
      capacity -= trip[0];
      if (capacity < 0) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  return 0;
}
