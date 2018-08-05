/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.20%)
 * Total Accepted:    219.9K
 * Total Submissions: 624.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int ai = 0, bi = 0, c = 0, sum = 0;
        int pa = a.size() - 1, pb = b.size() - 1;
        string s = a;
        if (a.size() < b.size() ) s = b;

        for (int i = 0; i < s.size(); ++i) {
            ai = pa - i < 0 ? 0 : a[pa - i] - '0';
            bi = pb - i < 0 ? 0 : b[pb - i] - '0';
            sum = ai + bi + c;
            s[s.size() - 1 - i] = sum & 1 ? '1' : '0';
            c = (sum & 2) >> 1;
        }

        if (c) return '1' + s;
        return s;
    }
};
