/*
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (31.09%)
 * Total Accepted:    142.8K
 * Total Submissions: 459.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
bool compare(const ListNode *one, const ListNode *two) {
	return one->val < two->val;
}

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head) return head;

		ListNode *node = head;
		vector<ListNode*> vec;
		while (node) {
			vec.push_back(node);
			node = node->next;
		}

		sort(vec.begin(), vec.end(), compare);
		for (int i(0); i < vec.size() - 1; ++i) {
			vec[i]->next = vec[i + 1];
		}

		vec[vec.size() - 1]->next = NULL;
		return vec[0];
	}
};