#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    int m = list1.size();
    int n = list2.size();
    unordered_set<string> hashset1(list1.begin(), list1.end());
    unordered_set<string> hashset2(list2.begin(), list2.end());
    unordered_map<string, int> restaurant_indexsum;
    
    for (int i = 0; i < m; ++i) {
      if (hashset2.count(list1[i])) {
        restaurant_indexsum[list1[i]] += i;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (hashset1.count(list2[i])) {
        restaurant_indexsum[list2[i]] += i;
      }
    }

    auto min_value = min_element(
      restaurant_indexsum.begin(),
      restaurant_indexsum.end(),
      [](const pair<string, int>& l, const pair<string, int>& r) {
      return l.second < r.second;
    });

    vector<string> result;
    for_each(
      restaurant_indexsum.begin(),
      restaurant_indexsum.end(),
      [&result, min_value](const pair<string, int>& item) {
      if (item.second == min_value->second) {
        result.push_back(item.first);
      }
    });

    return result;
  }
};

int main() {
  int m, n;
  cin >> m >> n;

  vector<string> list1(m);
  for (auto& item : list1) {
    cin >> item;
  }

  vector<string> list2(n);
  for (auto& item : list2) {
    cin >> item;
  }

  Solution solution;
  auto restaurants = solution.findRestaurant(list1, list2);
  for (const auto& restaurant : restaurants) {
    cout << restaurant << ' ';
  }
  cout << endl;
  return 0;
}
