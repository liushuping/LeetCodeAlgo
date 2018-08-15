/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (48.17%)
 * Total Accepted:    87.3K
 * Total Submissions: 181.3K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {};
        for (int c : magazine) m[c - 'a']++;
        for (int c : ransomNote) if (--m[c - 'a'] < 0) return false;
        return true;
    }
};
