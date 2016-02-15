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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res) {
        res.push_back(root->val);
        if (root->left) helper(root->left, res);
        if (root->right) helper(root->right, res);
    }
};