/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.89%)
 * Total Accepted:    538.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 */
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var pos = 0;
        var result = 0;
        var set = new HashSet<char>();
        
        for (int i = 0; i < s.Length; ++i) {
            var c = s[i];
            if (set.Contains(c)) {
                result = Math.Max(result, set.Count);
                while(s[pos] != c) {
                    set.Remove(s[pos++]);
                }
                pos++;
            } else {
                set.Add(c);
            }
        }
        
        return Math.Max(result, set.Count);
    }
}