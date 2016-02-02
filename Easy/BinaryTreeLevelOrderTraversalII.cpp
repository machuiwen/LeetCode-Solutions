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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // bfs
        vector<vector<int>> values;
        if (root == NULL) return values;
        queue<pair<TreeNode*, int>> nodes;
        nodes.push(pair<TreeNode*, int>(root, 0));
        while (!nodes.empty()) {
            pair<TreeNode*, int> temp = nodes.front();
            nodes.pop();
            TreeNode* cur = temp.first;
            int level = temp.second;
            if (level == values.size()) {
                values.push_back(vector<int>());
            }
            values[level].push_back(cur->val);
            if (cur->left) {
                nodes.push(pair<TreeNode*, int>(cur->left, level + 1));
            }
            if (cur->right) {
                nodes.push(pair<TreeNode*, int>(cur->right, level + 1));
            }
        }
        // reverse
        reverse(values.begin(), values.end());
        return values;
    }
};