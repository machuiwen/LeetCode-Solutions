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
    // Tag: DFS
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) return result;
        string cur = "";
        DFS(root, cur, result);
        return result;
    }
    void DFS(TreeNode* root, string& cur, vector<string>& result) {
        string append = string((cur == "") ? "" : "->") + to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(cur + append);
            return;
        }
        int size = cur.size();
        cur = cur + append;
        if (root->left != NULL) {
            DFS(root->left, cur, result);
        }
        if (root->right != NULL) {
            DFS(root->right, cur, result);
        }
        cur = cur.substr(0, size);
        return;
    }
};