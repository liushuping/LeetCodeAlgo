/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (45.83%)
 * Total Accepted:    194.2K
 * Total Submissions: 423.8K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 * 
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int i = nums.size() - 1; i >= 0; --i) sum -= nums[i];
        return sum;
    }
};
