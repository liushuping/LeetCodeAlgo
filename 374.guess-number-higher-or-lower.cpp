/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (37.35%)
 * Total Accepted:    81.8K
 * Total Submissions: 218.9K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows: 
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 * 
 * 
 * Example:
 * 
 * n = 10, I pick 6.
 * 
 * Return 6.
 * 
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
private:
    int guessNumber(long lower, long upper) {
        long x = (lower + upper) / 2;
        int y = guess(x);
        if (y == 0) return x;
        else if (y == -1)  return guessNumber(lower, x - 1);
        return guessNumber(x + 1, upper);
    }
    
public:
    
    int guessNumber(int n) {
        return guessNumber(1, n);
    }
};