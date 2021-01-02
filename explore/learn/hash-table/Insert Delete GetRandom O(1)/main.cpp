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
  RandomizedSet() : m_table(1000, list<int>{}), m_size(m_table.size()) {
    srand(time(NULL));
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
    
    const auto& bucket = m_table[rand() % m_size];


    
  }

private:
  list<int>& GetBucket(int key) {
    return m_table[key % m_size];
  }
  
  list<int>::iterator FindElement(int key) {
    auto& bucket = GetBucket(key);
    return find(bucket.begin(), bucket.end(), key);
  }

private:
  vector<list<int>> m_table;
  int m_size;
};

int main() {
  return 0;
}
