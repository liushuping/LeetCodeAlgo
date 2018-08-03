#
# [137] Single Number II
#
# https://leetcode.com/problems/single-number-ii/description/
#
# algorithms
# Medium (43.38%)
# Total Accepted:    141K
# Total Submissions: 325K
# Testcase Example:  '[2,2,3,2]'
#
# Given a non-empty array of integers, every element appears three times except
# for one, which appears exactly once. Find that single one.
# 
# Note:
# 
# Your algorithm should have a linear runtime complexity. Could you implement
# it without using extra memory?
# 
# Example 1:
# 
# 
# Input: [2,2,3,2]
# Output: 3
# 
# 
# Example 2:
# 
# 
# Input: [0,1,0,1,0,1,99]
# Output: 99
# 
#
class Solution:
   def singleNumber(self, array):
        fst = snd = aim = 0
        for num in array:
            tmp = fst & snd & num

            fst ^= tmp
            snd ^= tmp
            num ^= tmp
            aim ^= num

            tmp = fst & fst
            fst = tmp & num | snd
            snd = tmp | num

        return aim