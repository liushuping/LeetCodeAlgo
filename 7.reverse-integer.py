#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (24.38%)
# Total Accepted:    448.7K
# Total Submissions: 1.8M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
# 
# Example 1:
# 
# 
# Input: 123
# Output: 321
# 
# 
# Example 2:
# 
# 
# Input: -123
# Output: -321
# 
# 
# Example 3:
# 
# 
# Input: 120
# Output: 21
# 
# 
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
# this problem, assume that your function returns 0 when the reversed integer
# overflows.
# 
#
class Solution:
    def reverse(self, x):
        if x == 0: return 0;
        result = 0
        sign = x / abs(x)
        x = abs(x)
        
        while x > 0:
            if result > 214748364: return 0

            remaindar = x % 10
            #if (result == 214748364 and remaindar > 7): return 0

            result = result * 10 + remaindar
            x /= 10
        return result * sign