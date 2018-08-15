/*
 * [389] Find the Difference
 *
 * https://leetcode.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (51.76%)
 * Total Accepted:    115.9K
 * Total Submissions: 224K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 
 * Given two strings s and t which consist of only lowercase letters.
 * 
 * String t is generated by random shuffling string s and then add one more
 * letter at a random position.
 * 
 * Find the letter that was added in t.
 * 
 * Example:
 * 
 * Input:
 * s = "abcd"
 * t = "abcde"
 * 
 * Output:
 * e
 * 
 * Explanation:
 * 'e' is the letter that was added.
 * 
 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (char c : t) if (--m[c] < 0) return c;
    }
};