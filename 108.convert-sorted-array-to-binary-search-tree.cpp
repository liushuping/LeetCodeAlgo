/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (45.80%)
 * Total Accepted:    190.4K
 * Total Submissions: 415.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int mid = nums.size() / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = bst(nums, 0, mid - 1);
        node->right = bst(nums, mid + 1, nums.size() - 1);
        return node;
    }

    TreeNode* bst(const vector<int>& nums, int l, int r) {
        if (l == r) return new TreeNode(nums[l]);
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = bst(nums, l, mid - 1);
        node->right = bst(nums, mid + 1, r);
        return node;
    }
};
