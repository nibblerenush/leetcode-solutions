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
  bool wordPattern(string pattern, string s) {
    int i = 0;
    const int sLen = s.length();
    const int pLen = pattern.length();
    unordered_map<char, string> letterWord;
    unordered_set<string> usedWords;

    string word;
    for (char c : s)
    {
      if (c != ' ')
      {
        word.push_back(c);
      }
      else if (!word.empty())
      {
        if (i < pLen)
        {
          if (letterWord.count(pattern[i]))
          {
            if (letterWord[pattern[i]] != word)
            {
              return false;
            }
          }
          else if (!usedWords.count(word))
          {
            letterWord[pattern[i]] = word;
            usedWords.insert(word);
          }
          else
          {
            return false;
          }
          ++i;
        }
        else
        {
          return false;
        }
        word.clear();
      }
    }

    // Post processing
    if (!word.empty())
    {
      if (i < pLen)
      {
        if (letterWord.count(pattern[i]))
        {
          if (letterWord[pattern[i]] != word)
          {
            return false;
          }
        }
        else if (!usedWords.count(word))
        {
          letterWord[pattern[i]] = word;
          usedWords.insert(word);
        }
        else
        {
          return false;
        }
        ++i;
      }
      else
      {
        return false;
      }
    }

    return i == pLen;
  }
};

int main() {
  return 0;
}
