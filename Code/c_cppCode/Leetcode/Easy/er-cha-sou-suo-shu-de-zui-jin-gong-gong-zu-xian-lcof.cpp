#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // if (root == nullptr || root == p || root == q) return root;
        // if (p->val > q->val) swap(q,p);
        // if (root->val < p->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // if (root->val > q->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // return root;
        while (root != p && root != q) {
            if (root->val > min(p->val, q->val) && root->val < max(p->val, q->val)) break;
            root = root->val < min(p->val, q->val) ? root->right : root->left;
        }
        return root;
    }
};