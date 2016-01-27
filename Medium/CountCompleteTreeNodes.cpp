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
    int countNodes(TreeNode* root) {
        return helper(root, -1, -1);
    }
    
    int helper(TreeNode* root, int dl, int dr) {
        if (dl == -1) {
            dl = 0;
            TreeNode* pl = root;
            while (pl != NULL) {
                dl++;
                pl = pl->left;
            }
        }
        if (dr == -1) {
            dr = 0;
            TreeNode* pr = root;
            while (pr != NULL) {
                dr++;
                pr = pr->right;
            }
        }
        if (dl == dr) return (1 << dl) - 1;
        return helper(root->left, dl - 1, -1) + 1 + helper(root->right, -1, dr - 1);
    }
};