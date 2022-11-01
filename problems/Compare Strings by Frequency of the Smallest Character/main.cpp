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
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> wordFreqs;
    for (const auto& word : words) {
      wordFreqs.push_back(f(word));
    }
    sort(wordFreqs.begin(), wordFreqs.end());

    vector<int> result;
    for (const auto& query : queries) {
      int queryFreq = f(query);
      auto iter = upper_bound(wordFreqs.begin(), wordFreqs.end(), queryFreq);
      result.push_back(distance(iter, wordFreqs.end()));
    }

    return result;
  }

private:
  int f(const string& s) {
    auto iter = min_element(s.begin(), s.end());
    return count(s.begin(), s.end(), *iter);
  }
};

int main() {
  return 0;
}
