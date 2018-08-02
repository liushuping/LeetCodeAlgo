#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (41.39%)
# Total Accepted:    185.4K
# Total Submissions: 447.8K
# Testcase Example:  '5'
#
# Given a non-negative integer numRows, generate the first numRows of Pascal's
# triangle.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# 
# 
# Input: 5
# Output:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
# 
# 
#
data = [[1], [1, 1], [1, 2, 1]]

class Solution:
   def generate(self, n):
        if n <= len(data): return data[0:n]
        for x in range(len(data) - 1, n):
            last = data[-1]
            data.append([1] + [last[y] + last[y + 1] for y in range(0, len(last) - 1)] + [1]);
        return data[0: n]