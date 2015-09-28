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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry = 0; //
        while (l1 != NULL || l2 != NULL) {
            int digit = carry;
            if (l1 != NULL) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                digit += l2->val;
                l2 = l2->next;
            }
            carry = digit / 10;
            cur->next = new ListNode(digit % 10);
            cur = cur->next;
        }
        if (carry != 0) {
            cur->next = new ListNode(carry);
        }
        // delete the dummy head
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};