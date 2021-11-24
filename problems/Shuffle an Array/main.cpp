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
  Solution(vector<int>& nums)
    : m_nums(nums)
    , m_original_nums(nums)
  {
    srand(time(nullptr));
  }

  vector<int> reset()
  {
    m_nums = m_original_nums;
    return m_nums;
  }

  vector<int> shuffle()
  {
    int size = m_nums.size();
    for (int i = size - 1; i >= 0; --i)
    {
      int j = rand() % (i + 1);
      swap(m_nums[i], m_nums[j]);
    }

    return m_nums;
  }

private:
  vector<int> m_nums;
  const vector<int> m_original_nums;
};

int main() {
  return 0;
}
