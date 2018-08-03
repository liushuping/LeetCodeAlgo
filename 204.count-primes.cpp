/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.86%)
 * Total Accepted:    169.6K
 * Total Submissions: 631.5K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
	int countPrimes(int n);
};

int Solution::countPrimes(int n) {
	if (n <= 2) return 0;

	vector<short> vec(n - 2, 1);
	int count = 0;
	for (int i = 2; i <= sqrt(n - 1); ++i) {
		if (vec[i - 2] == 0) continue;

		for (int j = i; j <= (n - 1) / i; ++j) {
			vec[i * j - 2] = 0;
		}
	}


	for (int i = 0; i < n - 2; ++i) {
		count += vec[i];
	}

	return count;
}