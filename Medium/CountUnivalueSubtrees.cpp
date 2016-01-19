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
    int countUnivalSubtrees(TreeNode* root) {
        return countUnivalSubtreesRecur(root).first;
    }
    
    pair<int, int> countUnivalSubtreesRecur(TreeNode* root) {
        if (root == NULL) return pair<int, int>(0, 0);
        else if (root->left == NULL && root->right == NULL) return pair<int, int>(1, 1);
        pair<int, int> result = pair<int, int>();
        int val = root->val;
        pair<int, int> l = pair<int, int>(0, 0);
        pair<int, int> r = pair<int, int>(0, 0);
        bool flag = false;
        if (root->left != NULL) {
            l = countUnivalSubtreesRecur(root->left);
            flag |= root->left->val != val;
        }
        if (root->right != NULL) {
            r = countUnivalSubtreesRecur(root->right);
            flag |= root->right->val != val;
        }
        result.second = l.second + r.second + 1;
        result.first = l.first + r.first;
        if (l.first == l.second && r.first == r.second && !flag) {
            result.first++;
        }
        return result;
    }
};