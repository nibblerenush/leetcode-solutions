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
  int lengthLongestPath(string input) {
    const int inputLen = static_cast<int>(input.size());
    int currentLevel = -1;
    int currentSize = 0;
    int maxSize = 0;
    
    int level = 0;
    int itemSize = 0;
    bool isFile = false;
    bool isPrevFile = isFile;
    stack<int> workStack;
    
    for (int i = 0; i < inputLen; ++i) {
      if (input[i] == '\t') {
        ++level;
      }
      else if (input[i] != '\n' && input[i] != '\t') {
        ++itemSize;
        if (input[i] == '.') {
          isFile = true;
        }
      }
      else {
        if (level <= currentLevel) {
          if (isPrevFile) {
            maxSize = max(maxSize, currentSize - 1);
          }
          
          while (level <= currentLevel) {
            currentSize -= workStack.top();
            workStack.pop();
            --currentLevel;
          }
        }
        
        // "++" for slash
        workStack.push(++itemSize);
        currentSize += itemSize;
        ++currentLevel;

        level = 0;
        itemSize = 0;
        isPrevFile = isFile;
        isFile = false;
      }
    }
    
    // Post processing
    if (isFile) {
      if (level <= currentLevel) {
        if (isPrevFile) {
          maxSize = max(maxSize, currentSize - 1);
        }
        
        while (level <= currentLevel) {
          currentSize -= workStack.top();
          workStack.pop();
          --currentLevel;
        }
      }
      
      currentSize += itemSize;
      maxSize = max(maxSize, currentSize);
    }
    
    return maxSize;
  }
};

int main() {
  return 0;
}
