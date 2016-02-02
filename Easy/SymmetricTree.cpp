/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* root1, TreeNode* root2) {
        // base cases
        if (root1 == NULL && root2 == NULL) return true;
        else if (root1 == NULL || root2 == NULL) return false;
        // both not null
        return (root1->val == root2->val) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};

// Iterative - BFS
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        else if (root->left == NULL || root->right == NULL) return false;
        queue<TreeNode*> ql, qr;
        ql.push(root->left);
        qr.push(root->right);
        while (!ql.empty() && !qr.empty()) {
            TreeNode* l = ql.front();
            TreeNode* r = qr.front();
            ql.pop();
            qr.pop();
            if (l == NULL && r == NULL) continue;
            if (l->val != r->val) return false;
            if ((l->left && r->right) || (l->left == NULL && r->right == NULL)) {
                ql.push(l->left);
                qr.push(r->right);
            } else {
                return false;
            }
            if ((l->right && r->left) || (l->right == NULL && r->left == NULL)) {
                ql.push(l->right);
                qr.push(r->left);
            } else {
                return false;
            }
        }
        return true;
    }
};
