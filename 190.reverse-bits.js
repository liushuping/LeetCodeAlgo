/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.31%)
 * Total Accepted:    143.5K
 * Total Submissions: 489.7K
 * Testcase Example:  '    43261596 (00000010100101000001111010011100)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Example:
 * 
 * 
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as
 * 00000010100101000001111010011100, 
 * return 964176192 represented in binary as
 * 00111001011110000010100101000000.
 * 
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    var bin = n.toString(2);
    var c = 33 - bin.length;
    if (c > 1) bin = Array(c).join('0') + bin;
    var binArray = bin.split('');
    var binArrayReversed = binArray.reverse();
    var binReversed = binArrayReversed.join('');
    return parseInt(binReversed, 2);
};