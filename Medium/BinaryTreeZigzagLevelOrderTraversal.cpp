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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        queue<TreeNode*> q;
        q.push(root);
        bool order = true;
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (order) {
                    temp.push_back(t->val);
                } else {
                    temp.insert(temp.begin(), t->val);
                }
                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
            }
            res.push_back(temp);
            order = !order;
        }
        return res;
    }
};