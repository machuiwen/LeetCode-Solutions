/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connectHelper(root);
    }
    
    void connectHelper(TreeLinkNode*& root) {
        if (root == NULL) return;
        connectHelper(root->left);
        connectHelper(root->right);
        TreeLinkNode* l = root->left, *r = root->right;
        while (l) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
    }
};