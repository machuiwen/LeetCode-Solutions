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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        // assume input is valid
        if (p->right != NULL) {
            return findSmallest(p->right);
        } else {
            TreeNode* cur = NULL;
            TreeNode* search = root;
            while (search != p) {
                if (search->val < p->val) {
                    search = search->right;
                } else {
                    cur = search;
                    search = search->left;
                }
            }
            return cur;
        }
    }
    
    TreeNode* findSmallest(TreeNode* root) {
        TreeNode* cur = root;
        while (cur->left != NULL) {
            cur = cur->left;
        }
        return cur;
    }
};