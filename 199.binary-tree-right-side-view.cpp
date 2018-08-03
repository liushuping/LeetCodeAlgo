/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (43.66%)
 * Total Accepted:    118.6K
 * Total Submissions: 271.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> vec;
        rightSide(root, vec, 0);
        
        return vec;
    }
    
    void rightSide(TreeNode *node, vector<int> &vec, int depth) {
        if (node == NULL)
            return;
            
        if (depth == vec.size()) 
            vec.push_back(node->val);
            
        rightSide(node->right, vec, depth + 1);
        rightSide(node->left, vec, depth + 1);
    }
};
