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
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    const int n = position.size();
    int car_feet_count = 0;

    vector<pos_speed_t> pos_speed;
    for (int i = 0; i < n; ++i) {
      pos_speed.push_back({ position[i], speed[i] });
    }

    sort(pos_speed.begin(), pos_speed.end());

    stack<double> time_stack;
    for (int i = n - 1; i >= 0; --i) {
      double time = ((double)target - pos_speed[i].first) / pos_speed[i].second;

      while (!time_stack.empty() && time > time_stack.top()) {
        time_stack.pop();
      }

      if (time_stack.empty()) {
        ++car_feet_count;
      }

      time_stack.push(time);
    }

    return car_feet_count;
  }

private:
  using pos_speed_t = pair<int, int>;
};

int main() {
  return 0;
}
