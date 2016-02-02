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

    // DFS
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

// BFS solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* cur = temp.first;
            int depth = temp.second;
            if (cur->left == NULL && cur->right == NULL) return depth;
            if (cur->left != NULL) {
                q.push(pair<TreeNode*, int>(cur->left, depth + 1));
            }
            if (cur->right != NULL) {
                q.push(pair<TreeNode*, int>(cur->right, depth + 1));
            }
        }
    }
};