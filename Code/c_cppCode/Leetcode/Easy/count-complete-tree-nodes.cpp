#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int mostLeft(TreeNode *root) {
        if (root == nullptr) return 0;
        return 1 + mostLeft(root->left);
    }
    int solve(int d, int h, TreeNode *root) {
        if (root == nullptr) return 0;
        if (d == h) return 1;
        if (mostLeft(root->right) == h - d) {
            return (1 << (h - d)) + solve(d + 1, h, root->right);
        } else {
            return (1 << (h - d - 1)) + solve(d + 1, h, root->left);
        }
    }
    int countNodes(TreeNode *root) {
        return solve(1, mostLeft(root), root);
    }
};