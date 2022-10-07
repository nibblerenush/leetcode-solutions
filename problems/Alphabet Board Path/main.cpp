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
  string alphabetBoardPath(string target) {
    unordered_map<char, pair<int, int>> board;
    int i = 0;
    int j = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (j == 5) {
        ++i;
        j = 0;
      }
      
      board[c] = { i, j };
      ++j;
    }
    
    string path = "";
    pair<int, int> curPos = { 0, 0 };
    for (char c : target) {
      pair<int, int> targetPos = board[c];
      int upBottom = targetPos.first - curPos.first;
      int leftRight = targetPos.second - curPos.second;
      if (upBottom < 0) path.append(string(abs(upBottom), 'U'));
      if (leftRight < 0) path.append(string(abs(leftRight), 'L'));
      if (upBottom > 0) path.append(string(abs(upBottom), 'D'));
      if (leftRight > 0) path.append(string(abs(leftRight), 'R'));
      path.push_back('!');
      curPos = targetPos;
    }
    
    return path;
  }
};

int main() {
  return 0;
}
