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
    // Tricky: when the root has one child, then the other side cannot contain
    // leaf node, so we should not take the minDepth of that side into consideration
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else if (root->left == NULL) {
            return minDepth(root->right) + 1;
        } else if (root->right == NULL) {
            return minDepth(root->left) + 1;
        } else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};

// NOTE: for highly unbalanced tree, we can do breadth-first traversal!
// The space complexity in that case is O(N)