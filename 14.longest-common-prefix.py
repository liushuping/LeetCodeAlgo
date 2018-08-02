#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (31.79%)
# Total Accepted:    303K
# Total Submissions: 952.9K
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#
class Solution:
    def longestCommonPrefix(self, strs):
        if len(strs) < 1: return ""
        if len(strs) < 2: return strs[0]
        return self.longestCommonPrefix2(strs[0], strs[1:])

    def longestCommonPrefix2(self, str1, strs):
        if len(strs) < 1: return str1
        str2 = strs[0]
        result = ""
        count = min(len(str1), len(str2))
        for x in xrange(0, count):
            c = str1[x]
            if c == str2[x]: result += c
            else: break;

        return self.longestCommonPrefix2(result, strs[1:])