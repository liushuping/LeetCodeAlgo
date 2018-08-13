/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (39.46%)
 * Total Accepted:    92.3K
 * Total Submissions: 233.9K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        return !(num & num - 1 || num >> 1 & (num >> 1) - 1);
    }
};
