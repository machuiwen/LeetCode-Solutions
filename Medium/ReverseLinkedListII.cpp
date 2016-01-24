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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* next = head;
        for (int i = 0; i < m; i++) {
            prev = curr;
            curr = next;
            next = next->next;
        }
        ListNode* backPrev = prev;
        ListNode* back = curr;
        for (int i = m; i < n; i++) {
            prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        back->next = next;
        if (backPrev != NULL) {
            backPrev->next = curr;
            return head;
        } else {
            return curr;
        }
    }
};