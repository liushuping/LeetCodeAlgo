/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (27.63%)
 * Total Accepted:    161.5K
 * Total Submissions: 584.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
	string minWindow(string s, string t) {
		int size(s.size());
		int p, q, m(size + 1);
		int start(0), end(0);
		int remaining(t.size());
		int arr[128] = { 0 };

		for (auto itr = t.begin(); itr != t.end(); ++itr)
			arr[*itr]--;

		while (end < size) {
			if (arr[s[end]] < 0) remaining--;

			while (remaining == 0) {
				if (arr[s[start]] < 1) {
					remaining++;
					if (end - start < m) {
						m = end - start;
						p = start;
						q = end;
					}
				}

				arr[s[start++]]--;
			}

			arr[s[end++]]++;
		}

		return (m > size) ? "" : s.substr(p, q - p + 1);
	}
};
