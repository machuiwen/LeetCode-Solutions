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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        for (int i = 0; i < n; i++) fast = fast->next;
        ListNode* slow = dummy;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* trash = slow->next;
        slow->next = slow->next->next;
        delete trash;
        head = dummy->next;
        delete dummy;
        return head;
    }
};