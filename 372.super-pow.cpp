/*
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (34.83%)
 * Total Accepted:    22.3K
 * Total Submissions: 64.1K
 * Testcase Example:  '2\n[3]'
 *
 * 
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 * 
 * 
 * Example1:
 * 
 * a = 2
 * b = [3]
 * 
 * Result: 8
 * 
 * 
 * 
 * Example2:
 * 
 * a = 2
 * b = [1,0]
 * 
 * Result: 1024
 * 
 * 
 * 
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
#define k 1337

class Solution {
    int f(int a, int p) {
        if (p == 0) return 1;
        if (p == 1) return a % k;
        long x = f(a, p / 2);
        long y = f(a, p % 2);
        return x * x * y % k;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int x = b.back();
        b.pop_back();
        return f(a, x) * f(superPow(a, b), 10) % k;
    }
};