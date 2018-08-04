/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (42.48%)
 * Total Accepted:    382.3K
 * Total Submissions: 900K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto pl1 = &l1, pl2 = &l2;
        while(*pl1 && *pl2) {
            if ((*pl1)->val <= (*pl2)->val) pl1 = &(*pl1)->next;
            else {
                auto p = *pl1;
                *pl1 = *pl2;
                *pl2 = p;
            }
        }

        if (*pl2) *pl1 = *pl2;
        return l1;
    }
};
