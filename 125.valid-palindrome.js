/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.99%)
 * Total Accepted:    249.2K
 * Total Submissions: 890.5K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(str) {
    s = str.replace(/[^a-zA-Z0-9]/g, '');
    len = s.length;
    if (len < 2) return true;
    
    for (i = 0; i < len; ++i) {
        if (s[i].toLowerCase() !== s[len - i -1].toLowerCase()) return false;
    }
    
    return true
};