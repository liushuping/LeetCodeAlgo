#
# [191] Number of 1 Bits
#
# https://leetcode.com/problems/number-of-1-bits/description/
#
# algorithms
# Easy (40.73%)
# Total Accepted:    207.7K
# Total Submissions: 510.1K
# Testcase Example:  '           0 (00000000000000000000000000000000)'
#
# Write a function that takes an unsigned integer and returns the number of '1'
# bits it has (also known as the Hamming weight).
# 
# Example 1:
# 
# 
# Input: 11
# Output: 3
# Explanation: Integer 11 has binary representation
# 00000000000000000000000000001011 
# 
# 
# Example 2:
# 
# 
# Input: 128
# Output: 1
# Explanation: Integer 128 has binary representation
# 00000000000000000000000010000000
# 
# 
#
class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        vec = bin(n)
        return len([x for x in vec if x == '1'])
        