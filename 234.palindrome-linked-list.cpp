/*
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (33.99%)
 * Total Accepted:    178.7K
 * Total Submissions: 525.8K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
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
    bool isPalindrome(ListNode* head) {
        ListNode *t, *t1, *t2;
        t1 = head;
        t2 = head; 
        
        while(t2){
            t2 = t2->next;
            if (t2) 
                t2 = t2->next;
            t1 = t1->next;
        }
        
        while(t1) {
            t = t1;
            t1 = t1->next;
            t->next = t2;
            t2 = t;
        }
        
        t1 = head;
        while(t2 && t1) {
            if (t1->val != t2->val)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
    }
};