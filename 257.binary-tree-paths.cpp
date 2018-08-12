/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (42.53%)
 * Total Accepted:    174.2K
 * Total Submissions: 409.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> v;
        vector<string> vl = binaryTreePaths(root->left);
        vector<string> vr = binaryTreePaths(root->right);
        for (int i = 0; i < vl.size(); ++i)
            v.push_back(to_string(root->val) + "->" + vl[i]);
        for (int i = 0; i < vr.size(); ++i)
            v.push_back(to_string(root->val) + "->" + vr[i]);
        if (v.empty()) v.push_back(to_string(root->val));
        return v;
    }
};
