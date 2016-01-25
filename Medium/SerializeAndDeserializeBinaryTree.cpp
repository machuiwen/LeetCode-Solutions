/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        s = nodeToStr(root) + '|';
        if (root == NULL) return s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            s += nodeToStr(cur->left) + '|';
            s += nodeToStr(cur->right) + '|';
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return s;
    }
    
    string nodeToStr(TreeNode* root) {
        return (root == NULL) ? "_" : to_string(root->val);
    }
    
    TreeNode* strToNode(string& s,int& pos) {
        int newPos = s.find('|', pos);
        string subs = s.substr(pos, newPos - pos);
        pos = newPos + 1;
        if (subs == "_") return NULL;
        TreeNode* node = new TreeNode(stoi(subs));
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        TreeNode* root = strToNode(data, pos);
        if (root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            cur->left = strToNode(data, pos);
            if (cur->left) {
                q.push(cur->left);
            }
            cur->right = strToNode(data, pos);
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));