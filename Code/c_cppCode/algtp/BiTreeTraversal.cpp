#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode *node) {
  if (node != nullptr) {
    stack<TreeNode *> stk;
    stk.push(node);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      stk.pop();
      cout << cur->val << "\t";
      if (cur->right != nullptr) stk.push(cur->right);
      if (cur->left != nullptr) stk.push(cur->left);
    }
    cout << endl;
  }
}

void inOrder(TreeNode *node) {
  if (node != nullptr) {
    stack<TreeNode *> stk;
    while (!stk.empty() || node != nullptr) {
      if (node != nullptr) {
        stk.push(node);
        node = node->left;
      } else {
        node = stk.top();
        stk.pop();
        cout << node->val << "\t";
        node = node->right;
      }
    }
    cout << endl;
  }
}

void postOrder(TreeNode *node) {
  if (node != nullptr) {
    stack<TreeNode *> stk;
    stk.push(node);
    while (!stk.empty()) {
      TreeNode *cur = stk.top();
      if (cur->left != nullptr && node != cur->left && node != cur->right) {
        // Haven't visit left
        stk.push(cur->left);
      } else if (cur->right != nullptr && node != cur->right) {
        // Haven't vist right
        stk.push(cur->right);
      } else {
        // Only itself
        cout << cur->val;
        node = cur;
        stk.pop();
      }
    }
    cout << endl;
  }
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  preOrder(root);
  inOrder(root);
  return 0;
}