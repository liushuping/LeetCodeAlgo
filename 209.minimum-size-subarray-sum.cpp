/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (32.83%)
 * Total Accepted:    130.1K
 * Total Submissions: 396.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int i(0), j(0), sum(0), size(nums.size()), r(size);

		for (; sum < s && j < size; ++j)
			sum += nums[j];

		if (sum < s)
			return 0;

		do {
			while (sum - nums[i] >= s)
				sum -= nums[i++];

			int t(j - i);
			if (t < r)
				r = t;

			sum += nums[j];
		} while (j++ < size);

		return r;
	}
};
