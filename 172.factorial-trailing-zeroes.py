#
# [172] Factorial Trailing Zeroes
#
# https://leetcode.com/problems/factorial-trailing-zeroes/description/
#
# algorithms
# Easy (37.03%)
# Total Accepted:    125.8K
# Total Submissions: 339.7K
# Testcase Example:  '3'
#
# Given an integer n, return the number of trailing zeroes in n!.
# 
# Example 1:
# 
# 
# Input: 3
# Output: 0
# Explanation: 3! = 6, no trailing zero.
# 
# Example 2:
# 
# 
# Input: 5
# Output: 1
# Explanation: 5! = 120, one trailing zero.
# 
# Note: Your solution should be in logarithmic time complexity.
# 
#
class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        divider = 5
        result = 0
        multiplier = n / divider
        while multiplier > 0:
            result += multiplier
            divider *= 5
            multiplier = n / divider
        return result