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
    // https://leetcode.com/discuss/77946/recommend-beginners-implementation-detailed-explaination
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)    return NULL;
        ListNode *curA=headA, *curB=headB;
        while(curA && curB){
            if(curA==curB)  return curA;
            curA=curA->next;
            curB=curB->next;
            /*corner cases for my code :
            when the 2 linked-list do not meet, all the 2 pointers will be NULL at the same time.
            the 2 pointers can be NULL at the same time, if we continue processing, the loop will
            never end*/
            if(curA==curB)  return curA;
            if(curA==NULL)  curA=headB;
            if(curB==NULL)  curB=headA;
        }
        return curA;
    }
};