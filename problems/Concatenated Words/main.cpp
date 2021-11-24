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

class Solution {
private:
  struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_word_end = false;
  };

public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    // Init
    vector<string> result;
    m_root = new TrieNode();

    // Preprocessing
    sort(words.begin(), words.end(), [](const string& lh, const string& rh) {
      return lh.length() < rh.length();
    });
    
    // Main algorithm
    for (string& word : words) {
      if (word.empty()) {
        continue;
      }
      
      if (dfs(m_root, word, 0, 0)) {
        result.push_back(move(word));
      }
      else {
        TrieNode* cur_node = m_root;

        for (char c : word) {
          if (!cur_node->children.count(c)) {
            cur_node->children[c] = new TrieNode();
          }
          cur_node = cur_node->children[c];
        }
        
        cur_node->is_word_end = true;
      }
    }
    
    return result;
  }

private:
  bool dfs(const TrieNode* cur_node, const string& word, int index, int end_count) {
    if (index >= (int)word.length()) {
      return end_count > 0 && cur_node->is_word_end;
    }
    
    bool result = false;
    
    char c = word[index];
    if (cur_node->is_word_end) {
      result = result || dfs(m_root, word, index, end_count + 1);
    }
    
    if (cur_node->children.count(c)) {
      result = result || dfs(cur_node->children.at(c), word, index + 1, end_count);
    }
    
    return result;
  }

private:
  TrieNode* m_root = nullptr;
};

int main() {
  return 0;
}
