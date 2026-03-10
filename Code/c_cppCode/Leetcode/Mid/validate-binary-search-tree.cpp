#include <climits>
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
    long long minVal, maxVal;
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            minVal = LLONG_MAX;
            maxVal = LLONG_MIN;
            return true;
        }
        bool lValid = isValidBST(root->left);
        long long lmin = minVal, lmax = maxVal;
        bool rValid = isValidBST(root->right);
        long long rmin = minVal, rmax = maxVal;
        minVal = min(min(lmin, rmin), (long long)root->val);
        maxVal = max(max(lmax, rmax), (long long)root->val);
        return lValid && rValid && root->val > lmax && root->val < rmin;
    }
};