#include <iostream>
#include <queue>
#include <sstream>
#include <string>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Codec {
public:
  std::string serialize(TreeNode* root) {
    std::string result;
    if (!root) {
      return result;
    }
    
    result += std::to_string(root->val) + ' ';
    std::queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    
    while (!tree_queue.empty()) {
      TreeNode* cur_node = tree_queue.front();
      tree_queue.pop();

      if (cur_node->left) {
        result += std::to_string(cur_node->left->val) + ' ';
        tree_queue.push(cur_node->left);
      }
      else {
        result += "null ";
      }

      if (cur_node->right) {
        result += std::to_string(cur_node->right->val) + ' ';
        tree_queue.push(cur_node->right);
      }
      else {
        result += "null ";
      }
    }

    return result;
  }

  TreeNode* deserialize(std::string data) {
    std::istringstream oss(data);
    std::queue<std::string> val_queue;
    while (true) {
      std::string val;
      oss >> val;
      if (!oss) {
        break;
      }
      val_queue.push(std::move(val));
    }

    auto get_val = [](const std::string& val) -> TreeNode* {
      return val == "null" ? nullptr : new TreeNode{ std::stoi(val) };
    };

    TreeNode* root = nullptr;
    if (!val_queue.empty()) {
      root = get_val(val_queue.front());
      val_queue.pop();

      std::queue<TreeNode*> tree_queue;
      tree_queue.push(root);

      while (!tree_queue.empty()) {
        TreeNode* cur_node = tree_queue.front();
        tree_queue.pop();

        if (!cur_node) {
          continue;
        }

        if (!val_queue.empty()) {
          cur_node->left = get_val(val_queue.front());
          val_queue.pop();
        }

        if (!val_queue.empty()) {
          cur_node->right = get_val(val_queue.front());
          val_queue.pop();
        }

        tree_queue.push(cur_node->left);
        tree_queue.push(cur_node->right);
      }
    }
    
    return root;
  }
};

void PrintPreOrder(TreeNode* root) {
  if (!root) {
    return;
  }

  std::cout << root->val << ' ';
  PrintPreOrder(root->left);
  PrintPreOrder(root->right);
}

int main() {
  int n = 0;
  std::cin >> n;
  
  std::queue<std::string> val_queue;
  for (int i = 0; i < n; ++i) {
    std::string val;
    std::cin >> val;
    val_queue.push(std::move(val));
  }
  
  auto get_val = [](const std::string& val) -> TreeNode* {
    return val == "null" ? nullptr : new TreeNode{ std::stoi(val) };
  };
  
  TreeNode* root = nullptr;
  if (!val_queue.empty()) {
    root = get_val(val_queue.front());
    val_queue.pop();
    
    std::queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    
    while (!tree_queue.empty()) {
      TreeNode* cur_node = tree_queue.front();
      tree_queue.pop();

      if (!cur_node) {
        continue;
      }

      if (!val_queue.empty()) {
        cur_node->left = get_val(val_queue.front());
        val_queue.pop();
      }

      if (!val_queue.empty()) {
        cur_node->right = get_val(val_queue.front());
        val_queue.pop();
      }

      tree_queue.push(cur_node->left);
      tree_queue.push(cur_node->right);
    }
  }

  Codec codec;
  std::string tree = codec.serialize(root);
  std::cout << tree << std::endl;
  TreeNode* root_copy = codec.deserialize(tree);
  PrintPreOrder(root_copy);

  delete root;
  delete root_copy;
  return 0;
}
