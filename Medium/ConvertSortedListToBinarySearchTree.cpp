/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // Bottom-up recursion!
    // O(n) runtime, O(log n) stack space 
    // Each time you are stuck with the top-down approach, give bottom-up a try.
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTHelper(head, getListLength(head));
    }
    
    int getListLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    TreeNode* sortedListToBSTHelper(ListNode*& head, int length) {
        if (length <= 0) return NULL;
        TreeNode* leftChild = sortedListToBSTHelper(head, (length - 1) / 2);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        head = head->next;
        root->right = sortedListToBSTHelper(head, length / 2);
        return root;
    }
};