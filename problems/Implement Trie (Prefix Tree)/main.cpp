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

class Trie {
private:
  struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_word_end = false;
  };

public:
  Trie() : m_root(new TrieNode{})
  {}
  
  void insert(string word) {
    // init search
    TrieNode* cur_node = m_root;
    
    for (char c : word) {
      if (!cur_node->children.count(c)) {
        cur_node->children[c] = new TrieNode{};
      }
      cur_node = cur_node->children[c];
    }

    // set is_word_end
    cur_node->is_word_end = true;
  }

  bool search(string word) {
    TrieNode* end_node = search_prefix(word);
    return end_node ? end_node->is_word_end : false;
  }
  
  bool startsWith(string prefix) {
    return search_prefix(prefix);
  }

private:
  TrieNode* search_prefix(const string& word) {
    // init search
    TrieNode* cur_node = m_root;
    
    for (char c : word) {
      if (!cur_node->children.count(c)) {
        return nullptr;
      }
      cur_node = cur_node->children[c];
    }
    
    // end_node
    return cur_node;
  }

private:
  TrieNode* m_root;
};

int main() {
  return 0;
}
