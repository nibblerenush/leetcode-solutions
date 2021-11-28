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

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
 };
 
class NestedIterator {
public:
  NestedIterator(vector<NestedInteger>& nestedList)
  {
    dfs(nestedList);
  }

  int next()
  {
    return m_nums[idx++];
  }

  bool hasNext()
  {
    return idx < (int)m_nums.size();
  }

private:
  void dfs(const vector<NestedInteger>& nestedList)
  {
    int size = nestedList.size();
    for (int i = 0; i < size; ++i)
    {
      if (nestedList[i].isInteger())
      {
        m_nums.push_back(nestedList[i].getInteger());
      }
      else
      {
        dfs(nestedList[i].getList());
      }
    }
  }

private:
  vector<int> m_nums;
  int idx = 0;
};

int main() {
  return 0;
}
