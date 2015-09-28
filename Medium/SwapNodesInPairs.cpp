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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* temp = cur->next->next;
            cur->next->next = temp->next;
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

// SOLUTION2: recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // less than two nodes
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* nextHead = head->next->next;
        ListNode* temp = head->next;
        temp->next = head;
        head->next = swapPairs(nextHead);
        return temp;
    }
};