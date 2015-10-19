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
    int closestValue(TreeNode* root, double target) {
        assert(root != NULL);
        if (target < root->val) {
            if (root->left == NULL) {
                return root->val;
            } else {
                int temp = closestValue(root->left, target);
                return abs(temp - target) < abs(root->val - target) ? temp : root->val;
            }
        } else if (target > root->val) {
            if (root->right == NULL) {
                return root->val;
            } else {
                int temp = closestValue(root->right, target);
                return abs(temp - target) < abs(root->val - target) ? temp : root->val;
            }
        } else {
            return root->val;
        }
    }
};