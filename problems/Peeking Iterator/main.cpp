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

class Iterator {
public:
  struct Data;
  Data* data;
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  
  // Returns the next element in the iteration.
  int next();
  
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		m_is_cached = false;
		m_cached_value = 0;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (!m_is_cached) {
			m_is_cached = true;
			m_cached_value = Iterator::next();
		}
		return m_cached_value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (m_is_cached) {
			m_is_cached = false;
			return m_cached_value;
		}
		return Iterator::next();
	}

	bool hasNext() const {
		if (m_is_cached) {
			return true;
		}
		return Iterator::hasNext();
	}

private:
	int m_is_cached;
	int m_cached_value;
};

int main() {
  return 0;
}
