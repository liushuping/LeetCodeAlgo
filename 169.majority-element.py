#
# [169] Majority Element
#
# https://leetcode.com/problems/majority-element/description/
#
# algorithms
# Easy (49.01%)
# Total Accepted:    283.1K
# Total Submissions: 577.6K
# Testcase Example:  '[3,2,3]'
#
# Given an array of size n, find the majority element. The majority element is
# the element that appears more than ⌊ n/2 ⌋ times.
# 
# You may assume that the array is non-empty and the majority element always
# exist in the array.
# 
# Example 1:
# 
# 
# Input: [3,2,3]
# Output: 3
# 
# Example 2:
# 
# 
# Input: [2,2,1,1,1,2,2]
# Output: 2
# 
# 
#
class Solution:
    def majorityElement(self, num):
        count = 0
        key = num[0] 
        m = {key: 1}
        for x in num[1:]:
            if m.has_key(x):
                m[x] += 1
                if m[x] > m[key]: key = x;
            else: m[x] = 1

        return key