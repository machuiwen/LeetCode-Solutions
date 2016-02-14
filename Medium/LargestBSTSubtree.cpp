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
    int largestBSTSubtree(TreeNode* root) {
        if (root == NULL) return 0;
        return helper(root)[3];
    }
    
    vector<int> helper(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return vector<int> {1, root->val, root->val, 1};
        }
        vector<int> v1, v2, res(4, 0);
        if (root->left == NULL) {
            v2 = helper(root->right);
            if (v2[0] && root->val < v2[1]) {
                res = {1, root->val, v2[2], 1 + v2[3]};
            } else {
                res = {0, 0, 0, v2[3]};
            }
        } else if (root->right == NULL) {
            v1 = helper(root->left);
            if (v1[0] && root->val > v1[2]) {
                res = {1, v1[1], root->val, 1 + v1[3]};
            } else {
                res = {0, 0, 0, v1[3]};
            }
        } else {
            v1 = helper(root->left);
            v2 = helper(root->right);
            if (v1[0] && v2[0] && v1[2] < root->val && root->val < v2[1]) {
                res = {1, v1[1], v2[2], 1 + v1[3] + v2[3]};
            } else {
                res = {0, 0, 0, max(v1[3], v2[3])};
            }
        }
        return res;
    }
    
};