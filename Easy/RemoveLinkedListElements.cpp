/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode* trash = cur->next;
                cur->next = cur->next->next;
                delete trash;
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};