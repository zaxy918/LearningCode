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
    int yes, no;
    int rob(TreeNode *root) {
        solve(root);
        return max(yes, no);
    }

    void solve(TreeNode *root) {
        if (root == nullptr) {
            yes = 0;
            no = 0;
            return;
        }
        int curY = root->val;
        int curN = 0;
        solve(root->left);
        curY += no;
        curN += max(yes, no);
        solve(root->right);
        curY += no;
        curN += max(yes, no);
        yes = curY;
        no = curN;
    }
};