/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // This code doesn't handle the case of duplicate
        if (root == NULL) return root;
        if (root == p || root == q) {
            return root;
        }
        TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
        if (node1 != NULL && node2 != NULL) {
            return root;
        } else if (node1 != NULL) {
            return node1;
        } else if (node2 != NULL) {
            return node2;
        } else {
            return NULL;
        }
    }
};