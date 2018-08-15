/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.82%)
 * Total Accepted:    80.9K
 * Total Submissions: 208.4K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * 
 * Example 1:
 * 
 * Input: 16
 * Returns: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 14
 * Returns: False
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = num;
        if (x > 46340) x = 46340;
        while (x * x > num) x = (num / x + x)  >> 1;
        return x * x == num;
    }
};
