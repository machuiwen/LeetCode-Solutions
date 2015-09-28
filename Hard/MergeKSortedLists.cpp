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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = merge2Lists(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL) cur->next = l1;
        else if (l2 != NULL) cur->next = l2;
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};