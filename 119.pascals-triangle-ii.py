#
# [119] Pascal's Triangle II
#
# https://leetcode.com/problems/pascals-triangle-ii/description/
#
# algorithms
# Easy (39.35%)
# Total Accepted:    156.1K
# Total Submissions: 396.8K
# Testcase Example:  '3'
#
# Given a non-negative index k where k ≤ 33, return the kth index row of the
# Pascal's triangle.
# 
# Note that the row index starts from 0.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# 
# 
# Input: 3
# Output: [1,3,3,1]
# 
# 
# Follow up:
# 
# Could you optimize your algorithm to use only O(k) extra space?
# 
#
class Solution:
   def getRow(self, k):
        last = [1, 1]

        if k < 1: return [1]
        if k < 2: return last

        for x in range(1, k):
            last = [1] + [last[y] + last[y + 1] for y in range(0, len(last) - 1)] + [1]
            
        return last