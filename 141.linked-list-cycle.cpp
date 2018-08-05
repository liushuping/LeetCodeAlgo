/*
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (34.82%)
 * Total Accepted:    279.7K
 * Total Submissions: 803.3K
 * Testcase Example:  '[]\nno cycle'
 *
 * 
 * Given a linked list, determine if it has a cycle in it.
 * 
 * 
 * 
 * Follow up:
 * Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        auto p1 = head;
        auto p2 = head;
        while(true) {
            p2 = p2->next;
            if (!p2) return false;
            p2 = p2->next;
            if (!p2) return false;
            p1 = p1->next;
            if (p1 == p2) return true;
        }      
    }
};
