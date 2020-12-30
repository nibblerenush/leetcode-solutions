#include <algorithm>
#include <cassert>
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

class MyHashSet {
public:
  MyHashSet() : table(1000, list<int>{}), size(table.size())
  {}

  void add(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    if (iter == bucket.end()) {
      bucket.push_back(key);
    }
  }

  void remove(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    if (iter != bucket.end()) {
      bucket.erase(iter);
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    return iter != bucket.end();
  }

private:
  list<int>& GetBucket(int key) {
    return table[key % size];
  }
  
  list<int>::iterator FindElement(int key) {
    auto& bucket = GetBucket(key);
    return find(bucket.begin(), bucket.end(), key);
  }

private:
  vector<list<int>> table;
  int size = 0;
};

int main() {
  MyHashSet hashSet;
  hashSet.add(1);
  hashSet.add(2);
  assert(hashSet.contains(1)); // returns true
  assert(!hashSet.contains(3)); // returns false (not found)
  hashSet.add(2);
  assert(hashSet.contains(2)); // returns true
  hashSet.remove(2);
  assert(!hashSet.contains(2)); // returns false (already removed

  return 0;
}
