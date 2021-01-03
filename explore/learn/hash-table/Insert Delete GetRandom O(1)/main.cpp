#include <algorithm>
#include <ctime>
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

class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() : m_table(1000, list<int>{}), m_cur_size(0), m_size(m_table.size()) {
    srand(time(nullptr));
  }
  
  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);

    if (iter == bucket.end()) {
      bucket.push_back(key);
      return true;
    }
    return false;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);

    if (iter != bucket.end()) {
      bucket.erase(iter);
      return true;
    }
    return false;
  }
  
  /** Get a random element from the set. */
  int getRandom() {
    int v_idx = rand() % m_cur_size;
    const auto* bucket = &m_table[v_idx];
    
    if (bucket->empty()) {
      int left = v_idx - 1;
      int right = v_idx + 1;
      
      while (true) {
        if (left >= 0) {
          bucket = &m_table[left--];
          if (!bucket->empty()) { break; }
        }

        if (right < m_size) {
          bucket = &m_table[right++];
          if (!bucket->empty()) { break; }
        }
      }
    }

    int b_size = bucket->size();
    int b_idx = rand() % b_size;
    auto iter = next(bucket->begin(), b_idx);
    return *iter;
  }

private:
  list<int>& GetBucket(int key) {
    int v_idx = abs(key) % m_size;
    m_cur_size = max(m_cur_size, v_idx + 1);
    return m_table[v_idx];
  }
  
  list<int>::iterator FindElement(int key) {
    auto& bucket = GetBucket(key);
    return find(bucket.begin(), bucket.end(), key);
  }

private:
  vector<list<int>> m_table;
  int m_cur_size;
  int m_size;
};

int main() {
  RandomizedSet randomizedSet;

  randomizedSet.insert(1);
  randomizedSet.insert(10);
  randomizedSet.insert(20);
  randomizedSet.insert(30);

  cout << randomizedSet.getRandom() << endl;
  cout << randomizedSet.getRandom() << endl;
  cout << randomizedSet.getRandom() << endl;
  cout << randomizedSet.getRandom() << endl;
  cout << randomizedSet.getRandom() << endl;
  cout << randomizedSet.getRandom() << endl;

  return 0;
}
