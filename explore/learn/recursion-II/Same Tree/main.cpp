#include <iostream>
#include <queue>
#include <string>

using namespace std;

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

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }

    if (!check(p, q)) {
      return false;
    }

    queue<TreeNode*> pq;
    pq.push(p);

    queue<TreeNode*> qq;
    qq.push(q);

    while (!pq.empty()) {
      TreeNode* ptemp = pq.front();
      pq.pop();

      TreeNode* qtemp = qq.front();
      qq.pop();

      if (!check_and_push(pq, qq, ptemp->left, qtemp->left)) {
        return false;
      }

      if (!check_and_push(pq, qq, ptemp->right, qtemp->right)) {
        return false;
      }
    }
    return true;
  }

private:
  bool check_and_push(queue<TreeNode*>& pq, queue<TreeNode*>& qq, TreeNode* p, TreeNode* q) const {
    if (!check(p, q)) {
      return false;
    }

    if (p) {
      pq.push(p);
      qq.push(q);
    }
    return true;
  }

  bool check(TreeNode* p, TreeNode* q) const {
    if (!p && !q) {
      return true;
    }

    if (!p || !q) {
      return false;
    }

    if (p->val != q->val) {
      return false;
    }
    return true;
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  
  std::queue<std::string> val_queue;
  for (int i = 0; i < n; ++i) {
    std::string val;
    std::cin >> val;
    val_queue.push(std::move(val));
  }
  
  TreeNode* root = nullptr;
  if (!val_queue.empty()) {
    auto get_val = [](const std::string& val) -> TreeNode* {
      return val == "null" ? nullptr : new TreeNode{ std::stoi(val) };
    };
    
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

  Solution solution;
  std::cout << std::boolalpha << solution.isSameTree(root, root) << std::endl;
  delete root;
  return 0;
}
