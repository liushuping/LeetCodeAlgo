/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (51.12%)
 * Total Accepted:    167K
 * Total Submissions: 326.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int t1(1), t2(1);
        int size(nums.size());
        vector<int> result(size, 1);
        
        for (int i(1); i < size; ++i) {
            t1 *= nums[i - 1];
            result[i] *= t1;
            
            t2 *= nums[size - i];
            result[size - 1 - i] *= t2;
        }
        
        return result;
    }
};