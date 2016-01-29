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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* p1 = head;
        int i = 0;
        while (i < k && p1 != NULL) {
            p1 = p1->next;
            i++;
        }
        if (i == k && p1 == NULL) return head;
        if (p1 == NULL) {
            int j = 0;
            k %= i;
            p1 = head;
            while (j < k) {
                p1 = p1->next;
                j++;
            }
        }
        ListNode* p2 = head;
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};