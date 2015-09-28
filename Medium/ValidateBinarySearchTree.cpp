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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        return isValidBST(root->left) &&
               isValidBST(root->right) &&
               (root->left == NULL || findMax(root->left) < root->val) &&
               (root->right == NULL || findMin(root->right) > root->val);
    }
    int findMax(TreeNode* root) {
        // here root != NULL
        if (root->right == NULL) return root->val;
        else return findMax(root->right);
    }
    int findMin(TreeNode* root) {
        // here root != NULL
        if (root->left == NULL) return root->val;
        else return findMin(root->left);
    }
};