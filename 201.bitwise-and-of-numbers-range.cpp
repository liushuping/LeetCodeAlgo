/*
 * [201] Bitwise AND of Numbers Range
 *
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (34.79%)
 * Total Accepted:    69K
 * Total Submissions: 198.5K
 * Testcase Example:  '5\n7'
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
 * of all numbers in this range, inclusive.
 * 
 * Example 1:
 * 
 * 
 * Input: [5,7]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1]
 * Output: 0
 * 
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0)
            return 0;
            
        int factor(1);
        while (m != n) {
            m >>= 1;
            n >>= 1;
            factor <<= 1;
        }
        
        return m * factor;
    }
};