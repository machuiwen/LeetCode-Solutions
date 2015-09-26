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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Use dummyHead to simply code
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL) {
            cur->next = l1;
        } else if (l2 != NULL) {
            cur->next = l2;
        }
        return dummyHead->next;
    }
};

// Notes:
// To see more examples of dummy head usage, please see these questions: [21. Add Two Numbers], [22. Swap Nodes in Pairs], and [23. Merge K Sorted Linked Lists].