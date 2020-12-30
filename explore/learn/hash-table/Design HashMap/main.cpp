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

class MyHashMap {
public:
  MyHashMap() : table(1000, list<pair<int, int>>{}), size(table.size())
  {}

  void put(int key, int value) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    if (iter == bucket.end()) {
      bucket.push_back({ key, value });
    }
    else {
      iter->second = value;
    }
  }

  int get(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    return iter != bucket.end() ? iter->second : -1;
  }

  void remove(int key) {
    auto& bucket = GetBucket(key);
    auto iter = FindElement(key);
    if (iter != bucket.end()) {
      bucket.erase(iter);
    }
  }

private:
  list<pair<int, int>>& GetBucket(int key) {
    return table[key % size];
  }
  
  list<pair<int, int>>::iterator FindElement(int key) {
    auto& bucket = GetBucket(key);
    return find_if(bucket.begin(), bucket.end(), [key](const pair<int, int>& item) {
      return item.first == key;
    });
  }

private:
  vector<list<pair<int, int>>> table;
  int size = 0;
};

int main() {
  MyHashMap hashMap;
  hashMap.put(1, 1);
  hashMap.put(2, 2);
  assert(hashMap.get(1) == 1); // returns 1
  assert(hashMap.get(3) == -1); // returns -1 (not found)
  hashMap.put(2, 1); // update the existing value
  assert(hashMap.get(2) == 1); // returns 1 
  hashMap.remove(2); // remove the mapping for 2
  assert(hashMap.get(2) == -1); // returns -1 (not found) 

  return 0;
}
