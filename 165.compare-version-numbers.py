#
# [165] Compare Version Numbers
#
# https://leetcode.com/problems/compare-version-numbers/description/
#
# algorithms
# Medium (21.25%)
# Total Accepted:    106.4K
# Total Submissions: 500.4K
# Testcase Example:  '"0.1"\n"1.1"'
#
# Compare two version numbers version1 and version2.
# If version1 > version2 return 1; if version1 < version2 return -1;otherwise
# return 0.
# 
# You may assume that the version strings are non-empty and contain only digits
# and the . character.
# The . character does not represent a decimal point and is used to separate
# number sequences.
# For instance, 2.5 is not "two and a half" or "half way to version three", it
# is the fifth second-level revision of the second first-level revision.
# 
# Example 1:
# 
# 
# Input: version1 = "0.1", version2 = "1.1"
# Output: -1
# 
# Example 2:
# 
# 
# Input: version1 = "1.0.1", version2 = "1"
# Output: 1
# 
# Example 3:
# 
# 
# Input: version1 = "7.5.2.4", version2 = "7.5.3"
# Output: -1
# 
#
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        return self.compareVersionList(version1.split("."), version2.split("."))

    def compareVersionList(self, v1, v2):
        if v1 == [] and v2 == []: return 0
        elif v1 == []:
            if int(v2[0]) > 0: return -1
            else: return self.compareVersionList([], v2[1:])
        elif v2 == []:
            if int(v1[0]) > 0: return 1
            else: return self.compareVersionList(v1[1:], [])
        elif int(v1[0]) > int(v2[0]): return 1
        elif int(v1[0]) < int(v2[0]): return -1
        return self.compareVersionList(v1[1:], v2[1:])