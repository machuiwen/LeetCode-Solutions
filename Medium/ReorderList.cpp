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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        // split
        ListNode* fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = slow->next, *prev = NULL;
        slow->next = NULL;
        // reverse
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        // merge
        while (prev) {
            ListNode* nxt1 = head->next, *nxt2 = prev->next;
            head->next = prev;
            prev->next = nxt1;
            head = nxt1;
            prev = nxt2;
        }
    }
};