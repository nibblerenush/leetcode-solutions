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

class RandomizedSet
{
public:
  RandomizedSet()
  {
    srand(time(nullptr));
  }

  bool insert(int val)
  {
    if (m_number_index.count(val))
    {
      return false;
    }
    else
    {
      m_nums.push_back(val);
      m_number_index[val] = (int)m_nums.size() - 1;
      return true;
    }
  }
  
  bool remove(int val)
  {
    if (m_number_index.count(val))
    {
      int rm_index = m_number_index[val];
      int last_index = m_nums.size() - 1;
      int last_value = m_nums.back();
      
      swap(m_nums[rm_index], m_nums[last_index]);
      m_number_index[last_value] = rm_index;
      
      m_nums.pop_back();
      m_number_index.erase(val);
      
      return true;
    }
    else
    {
      return false;
    }
  }
  
  int getRandom()
  {
    int index = rand() % m_nums.size();
    return m_nums[index];
  }

private:
  vector<int> m_nums;
  unordered_map<int, int> m_number_index;
};

int main() {
  return 0;
}
