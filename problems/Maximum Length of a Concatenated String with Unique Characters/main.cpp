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
  int maxLength(vector<string>& arr) {
    backtrack(0, arr, 0);
    return result;
  }

private:
  void backtrack(int index, const vector<string>& arr, int curLen) {
    result = max(result, curLen);
    const int arrSize = static_cast<int>(arr.size());

    for (int i = index; i < arrSize; ++i) {
      if (isUnique(arr[i])) {
        addStr(arr[i]);
        backtrack(i + 1, arr, curLen + arr[i].size());
        delStr(arr[i]);
      }
    } 
  }

  bool isUnique(const string& str) {
    unordered_map<char, int> charCount;
    for (char c : str) {
      ++charCount[c];
      if (charCount[c] > 1) {
        return false;
      }
    }

    for (char c : str) {
      if (m_usedChars.count(c)) {
        return false;
      }
    } 
    return true;
  }

  void addStr(const string& str) {
    for (char c : str) {
      m_usedChars.insert(c);
    }
  }

  void delStr(const string& str) {
    for (char c : str) {
      m_usedChars.erase(c);
    }
  }

private:
  unordered_set<char> m_usedChars;
  int result = 0;
};

int main() {
  return 0;
}
