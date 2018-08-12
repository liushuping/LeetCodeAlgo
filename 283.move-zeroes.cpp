/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.14%)
 * Total Accepted:    325.1K
 * Total Submissions: 623.4K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(nums[i]) ++i;
        int j = i + 1;
        while(j < nums.size()) {
            if (!nums[j]) ++j;
            else {
                nums[i] = nums[j];
                nums[j++] = 0;
                while(nums[i]) ++i;
            }
        }
    }
};
