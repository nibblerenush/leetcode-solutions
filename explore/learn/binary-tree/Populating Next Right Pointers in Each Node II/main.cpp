#include <iostream>
#include <queue>
#include <string>

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  void traverse(Node* root) {
    if (!root) {
      return;
    }

    if (root->left || root->right) {
      Node* child = nullptr;
      if (root->left && root->right) {
        root->left->next = root->right;
        child = root->right;
      }
      else {
        child = root->left ? root->left : root->right;
      }

      Node* root_next = root->next;
      while (root_next) {
        if (root_next->left) {
          child->next = root_next->left;
          break;
        }
        else if (root_next->right) {
          child->next = root_next->right;
          break;
        }
        root_next = root_next->next;
      }
    }

    traverse(root->right);
    traverse(root->left);
  }

  Node* connect(Node* root) {
    traverse(root);
    return root;
  }
};

void PreorderPrint(Node* root) {
  if (!root) {
    return;
  }

  std::cout << root->val << " -> " << (root->next ? std::to_string(root->next->val) : "NULL") << std::endl;
  PreorderPrint(root->left);
  PreorderPrint(root->right);
}

int main() {
  int n = 0;
  std::cin >> n;
  
  Node* root = nullptr;
  Node* cur_node = nullptr;
  std::queue<Node*> work_queue;
  
  auto get_val = [](const std::string& val) -> Node* {
    return val == "null" ? nullptr : new Node{ std::stoi(val) };
  };
  
  for (int i = 0; i < n; ++i) {
    std::string val;
    std::cin >> val;
    
    if (i == 0) {
      root = get_val(val);
      work_queue.push(root);
      continue;
    }
    
    if (i % 2 != 0) {
      cur_node = work_queue.front();
      work_queue.pop();
      
      if (cur_node) {
        cur_node->left = get_val(val);
        work_queue.push(cur_node->left);
      }
    }
    else {
      if (cur_node) {
        cur_node->right = get_val(val);
        work_queue.push(cur_node->right);
      }
    }
  }

  Solution solution;
  root = solution.connect(root);
  PreorderPrint(root);
  delete root;
  return 0;
}
/*
15
2 1 3 0 7 9 1 2 null 1 0 null null 8 8
*/