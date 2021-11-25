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
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    auto ab_hashmap = sum(A, B);
    auto cd_hashmap = sum(C, D);
    
    int result = 0;
    for (const auto& ab_item : ab_hashmap) {
      if (cd_hashmap.count(-ab_item.first)) {
        result += (ab_item.second * cd_hashmap[-ab_item.first]);
      }
    }
    return result;
  }

private:
  unordered_map<int, int> sum(const vector<int>& v1, const vector<int>& v2) {
    int size = v1.size();
    unordered_map<int, int> result;
    
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        int elem_sum = v1[i] + v2[j];
        ++result[elem_sum];
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
