/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.32%)
 * Total Accepted:    255.2K
 * Total Submissions: 870.4K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        return mySqrt(0, max(min(46340, x / 2), 1), x);
    }

    int mySqrt(int l, int r, int x) {
        if (l + 1 >= r) {
            if (r * r <= x) return r;
            return l;
        }

        int m = (l + r) / 2;
        if (m * m == x) return m;
        if (m * m > x) return mySqrt(l, m - 1, x);
        return mySqrt(m, r, x);
    }
};
