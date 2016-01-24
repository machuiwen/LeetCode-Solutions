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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* next = head;
        while (next != NULL) {
            prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        return curr;
    }
};