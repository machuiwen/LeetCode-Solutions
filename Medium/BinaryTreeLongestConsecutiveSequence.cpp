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
    int longestConsecutive(TreeNode* root) {
        pair<int, int> temp = longestConsecutiveRecur(root);
        return max(temp.first, temp.second);
    }
    // <not containing root, containing root>
    pair<int, int> longestConsecutiveRecur(TreeNode* root) {
        if (root == NULL) return pair<int, int>(0, 0);
        else if (root->left == NULL && root->right == NULL) return pair<int, int>(1, 1);
        pair<int, int> result = pair<int, int>(0, 0);
        pair<int, int> l, r;
        if (root->left != NULL) {
            l = longestConsecutiveRecur(root->left);
            if (root->left->val == root->val + 1) {
                result.first = max(result.first, l.first);
                result.second = max(result.second, 1 + l.second);
            } else {
                result.first = max(max(l.first, l.second), result.first);
                result.second = max(result.second, 1);
            }
        }
        if (root->right != NULL) {
            r = longestConsecutiveRecur(root->right);
            if (root->right->val == root->val + 1) {
                result.first = max(result.first, r.first);
                result.second = max(result.second, 1 + r.second);
            } else {
                result.first = max(max(r.first, r.second), result.first);
                result.second = max(result.second, 1);
            }
        }
        return result;
    }
};


// Other's solution
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
private:
    int helper(TreeNode* root, TreeNode* parent, int length) {
        if (root == NULL) return length;
        length = (parent && root->val == (parent->val + 1)) ? length + 1 : 1;
        return max(length, max(helper(root->left, root, length), helper(root->right, root, length)));
    }
};