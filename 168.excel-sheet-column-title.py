#
# [168] Excel Sheet Column Title
#
# https://leetcode.com/problems/excel-sheet-column-title/description/
#
# algorithms
# Easy (27.76%)
# Total Accepted:    144.3K
# Total Submissions: 519.6K
# Testcase Example:  '1'
#
# Given a positive integer, return its corresponding column title as appear in
# an Excel sheet.
# 
# For example:
# 
# 
# ⁠   1 -> A
# ⁠   2 -> B
# ⁠   3 -> C
# ⁠   ...
# ⁠   26 -> Z
# ⁠   27 -> AA
# ⁠   28 -> AB 
# ⁠   ...
# 
# 
# Example 1:
# 
# 
# Input: 1
# Output: "A"
# 
# 
# Example 2:
# 
# 
# Input: 28
# Output: "AB"
# 
# 
# Example 3:
# 
# 
# Input: 701
# Output: "ZY"
# 
# 
#
class Solution:
    # @return a string
    def convertToTitle(self, num):
        if num < 27: return chr(num + 64)
        high = num / 26
        low = num % 26
        if low == 0: 
            low = 26
            high -= 1

        return self.convertToTitle(high) + self.convertToTitle(low)