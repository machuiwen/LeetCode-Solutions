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
    // assumption: root != NULL
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        if (target < root->val && root->left) {
            int tl = closestValue(root->left, target);
            if (abs(target - tl) < (closest - target)) closest = tl;
        } else if (target > root->val && root->right) {
            int tr = closestValue(root->right, target);
            if (abs(target - tr) < (target - closest)) closest = tr;
        }
        return closest;
    }
};