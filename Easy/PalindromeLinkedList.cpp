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
    // O(n) time, O(1) space
    // Ref: http://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        // slow will be the middle point
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the second half
        ListNode* l2 = reverse(slow->next);
        // compare with the first half
        ListNode* cur1 = head, *cur2 = l2;
        while (cur2) {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        // reverse the second half again and append to
        // the first half
        slow->next = reverse(l2);
        return head;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL, *cur = NULL, *next = head;
        while (next) {
            prev = cur;
            cur = next;
            next = next->next;
            cur->next = prev;
        }
        return cur;
    }
};

// O(n) space, straight forward solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;
        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        return isPalindromeVector(v);
    }
    
    bool isPalindromeVector(vector<int>& v) {
        int i = 0, j = v.size() - 1;
        while (i < j) {
            if (v[i++] != v[j--]) return false;
        }
        return true;
    }
};