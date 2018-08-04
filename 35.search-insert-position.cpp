/*
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.05%)
 * Total Accepted:    282K
 * Total Submissions: 704.1K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsert(nums, 0, nums.size() - 1, target);
    }

    int searchInsert(const vector<int>& nums, int lower, int upper, int target) {
        if (lower + 1 >= upper) {
            if (target <= nums[lower]) return lower;
            else if (target <= nums[upper]) return upper;
            else return upper + 1;
        }
        int mid = (lower + upper) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return searchInsert(nums, mid, upper, target);
        else return searchInsert(nums, lower, mid, target);
    }
};
