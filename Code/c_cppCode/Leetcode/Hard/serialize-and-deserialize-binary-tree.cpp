#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "";
        ostringstream oser;
        preOrderSer(root, oser);
        return oser.str();
        // return levelOrderSer(root);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream iss(data);
        string token;
        vector<string> ser;
        while (getline(iss, token, ',')) {
            ser.push_back(token);
        }
        return preOrderDeser(ser);
        // return levelOrderDeser(ser);
    }

    void preOrderSer(TreeNode *root, ostringstream &ser) {
        if (root == nullptr) {
            ser << "#,";
            return;
        }
        ser << to_string(root->val) << ",";
        preOrderSer(root->left, ser);
        preOrderSer(root->right, ser);
    }

    int cnt;
    TreeNode *preOrderDeser(vector<string> &ser) {
        string cur = ser[cnt++];
        if (cur == "#") {
            return nullptr;
        } else {
            TreeNode *root = new TreeNode(stoi(cur));
            root->left = preOrderDeser(ser);
            root->right = preOrderDeser(ser);
            return root;
        }
    }

    const static int MAX_N = 10001;
    TreeNode *q[MAX_N];
    int h, t;

    string levelOrderSer(TreeNode *root) {
        ostringstream oss;
        h = t = 0;
        q[t++] = root;
        while (h < t) {
            TreeNode *node = q[h++];
            oss << node->val << ",";
            if (node->left == nullptr) {
                oss << "#,";
            } else {
                q[t++] = node->left;
            }
            if (node->right == nullptr) {
                oss << "#,";
            } else {
                q[t++] = node->right;
            }
        }
        return oss.str();
    }
    TreeNode *levelOrderDeser(vector<string> &ser) {
        h = t = 0;
        cnt = 0;
        TreeNode *root = geneNode(ser[cnt++]);
        if (root != nullptr) q[t++] = root;
        while (h < t) {
            TreeNode *node = q[h++];
            node->left = geneNode(ser[cnt++]);
            node->right = geneNode(ser[cnt++]);
            if (node->left != nullptr) {
                q[t++] = node->left;
            }
            if (node->right != nullptr) {
                q[t++] = node->right;
            }
        }
        return root;
    }
    TreeNode *geneNode(string val) {
        return val == "#" ? nullptr : new TreeNode(stoi(val));
    }
};