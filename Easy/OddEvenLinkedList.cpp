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
        ListNode* insertPosition = head;
        ListNode* grabPosition = head->next; 
        while (grabPosition != NULL && grabPosition->next != NULL) {
            ListNode* insertNext = insertPosition->next;
            ListNode* grabNode = grabPosition->next;
            ListNode* grabNext = grabNode->next;
            insertPosition->next = grabNode;
            grabNode->next = insertNext;
            grabPosition->next = grabNext;
            insertPosition = grabNode;
            grabPosition = grabNext;
        }
        return head;
    }
};