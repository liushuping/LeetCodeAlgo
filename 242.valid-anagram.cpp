/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (48.46%)
 * Total Accepted:    235.9K
 * Total Submissions: 486.8K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        int m[26] = {}; 
        for (int i = 0; i < s.size(); ++i) m[s[i] - 'a']++;
        for (int i = 0; i < t.size(); ++i) m[t[i] - 'a']--;
        for (int i = 0; i < 26; ++i) 
            if (m[i] != 0) return false;

        return true;
    }
};
