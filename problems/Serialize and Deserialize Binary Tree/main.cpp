#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  string serialize(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    string result;
    result += to_string(root->val) + ' ';
    
    queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    
    auto add_node = [&result, &tree_queue](TreeNode* node) {
      if (node) {
        result += to_string(node->val) + ' ';
        tree_queue.push(node);
      }
      else {
        result += "null ";
      }
    };
    
    while (!tree_queue.empty()) {
      TreeNode* cur_node = tree_queue.front();
      tree_queue.pop();

      add_node(cur_node->left);
      add_node(cur_node->right);
    }
    
    return result;
  }
  
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    
    istringstream oss(data);
    queue<string> value_queue;
    
    string value;
    while (oss >> value) {
      value_queue.push(move(value));
    }
    
    auto get_value = [](const string& value) -> TreeNode* {
      return value != "null" ? new TreeNode(stoi(value)) : nullptr;
    };
    
    TreeNode* root = get_value(value_queue.front());
    value_queue.pop();
    
    queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    
    while (!tree_queue.empty()) {
      TreeNode* cur_node = tree_queue.front();
      tree_queue.pop();
      
      if (cur_node) {
        if (!value_queue.empty()) {
          cur_node->left = get_value(value_queue.front());
          value_queue.pop();
        }
        
        if (!value_queue.empty()) {
          cur_node->right = get_value(value_queue.front());
          value_queue.pop();
        }
        
        tree_queue.push(cur_node->left);
        tree_queue.push(cur_node->right);
      }
    }
    
    return root;
  }
};

int main() {
  return 0;
}
