#
# [171] Excel Sheet Column Number
#
# https://leetcode.com/problems/excel-sheet-column-number/description/
#
# algorithms
# Easy (49.36%)
# Total Accepted:    179.2K
# Total Submissions: 363K
# Testcase Example:  '"A"'
#
# Given a column title as appear in an Excel sheet, return its corresponding
# column number.
# 
# For example:
# 
# 
# ⁠   A -> 1
# ⁠   B -> 2
# ⁠   C -> 3
# ⁠   ...
# ⁠   Z -> 26
# ⁠   AA -> 27
# ⁠   AB -> 28 
# ⁠   ...
# 
# 
# Example 1:
# 
# 
# Input: "A"
# Output: 1
# 
# 
# Example 2:
# 
# 
# Input: "AB"
# Output: 28
# 
# 
# Example 3:
# 
# 
# Input: "ZY"
# Output: 701
# 
# 
#
class Solution:
    def titleToNumber(self, s):
        result = 0
        for x in s:
            result *= 26
            result += ord(x) - 64
        return result