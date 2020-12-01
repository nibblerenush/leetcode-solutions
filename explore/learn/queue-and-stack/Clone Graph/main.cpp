#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }

  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  void helper(Node* old_node,
    std::unordered_map<Node*, Node*>& old_new,
    std::unordered_set<Node*>& visited,
    Node*& new_node)
  {
    if (visited.count(old_node)) {
      return;
    }
    visited.insert(old_node);
    
    if (!new_node) {
      new_node = new Node(old_node->val);
      old_new[old_node] = new_node;
    }
    
    for (Node* neighbor : old_node->neighbors) {
      if (old_new.count(neighbor)) {
        new_node->neighbors.push_back(old_new[neighbor]);
      }
      else {
        Node* new_neighbor = new Node(neighbor->val);
        new_node->neighbors.push_back(new_neighbor);
        old_new[neighbor] = new_neighbor;
      }
      helper(neighbor, old_new, visited, new_node->neighbors.back());
    }
  }

  Node* cloneGraph(Node* node) {
    std::unordered_map<Node*, Node*> old_new;
    std::unordered_set<Node*> visited;
    visited.insert(nullptr);
    
    Node* result = nullptr;
    helper(node, old_new, visited, result);
    return result;
  }
};

int main() {
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);

  node3->neighbors.push_back(node1);
  node3->neighbors.push_back(node2);

  Solution solution;
  Node* result = solution.cloneGraph(node1);

  delete node1;
  delete node2;
  delete node3;

  delete result->neighbors[0];
  delete result->neighbors[1];
  delete result;

  return 0;
}
