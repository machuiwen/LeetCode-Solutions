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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        map<int, vector<int>> table;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* t = temp.first;
            int bias = temp.second;
            table[bias].push_back(t->val);
            if (t->left != NULL) {
                q.push(pair<TreeNode*, int>(t->left, bias - 1));
            }
            if (t->right != NULL) {
                q.push(pair<TreeNode*, int>(t->right, bias + 1));
            }
        }
        vector<vector<int>> result;
        for (auto p: table) {
            result.push_back(p.second);
        }
        return result;
    }
};