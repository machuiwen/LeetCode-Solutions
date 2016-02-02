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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* h2 = head->next;
        ListNode* l1 = head, *l2 = h2;
        while (l2 && l2->next) {
            l1->next = l2->next;
            l2->next = l2->next->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->next = h2;
        return head;
    }
};