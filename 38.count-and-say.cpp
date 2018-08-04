/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.51%)
 * Total Accepted:    209.3K
 * Total Submissions: 558K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        char c = str[0];
        int count = 1;
        string res;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == c) count++;
            else {
                res += to_string(count);
                res += c;
                count = 1;
                c = str[i];
            }
        }

        res += to_string(count);
        res += c;
        return res;
    }
};
