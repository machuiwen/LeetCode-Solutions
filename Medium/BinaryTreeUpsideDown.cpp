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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* newRoot;
        upsideDownBinaryTreeHelper(root, newRoot);
        return newRoot;
    }
    
    void upsideDownBinaryTreeHelper(TreeNode* root, TreeNode*& newRoot) {
        if (root->left == NULL) {
            newRoot = root;
            return;
        }
        TreeNode* leftChild = root->left;
        upsideDownBinaryTreeHelper(leftChild, newRoot);
        leftChild->left = root->right;
        leftChild->right = root;
        root->left = NULL;
        root->right = NULL;
    }
};