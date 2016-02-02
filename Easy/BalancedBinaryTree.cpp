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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = height(root->left);
        if (leftDepth == -1) return -1;
        int rightDepth = height(root->right);
        if (rightDepth == -1) return -1;
        if (abs(leftDepth - rightDepth) > 1) return -1;
        return 1 + max(leftDepth, rightDepth);
    }
};