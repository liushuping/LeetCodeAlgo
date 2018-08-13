/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.80%)
 * Total Accepted:    112.4K
 * Total Submissions: 332.6K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 */
#include <sstream>
class Solution {
public:
    bool wordPattern(string pattern, string str) {
	unordered_map<char, string> m1;
	unordered_map<string, char> m2;
	vector<char> v1;
	vector<string> v2;
	string s;
	istringstream ss(str);
	for (int i = 0; i < pattern.size(); ++i) v1.push_back(pattern[i]);
	while (!ss.eof()) {
	    ss >> s;
	    v2.push_back(s);
	}

	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); ++i) {
	    auto f1 = m1.find(v1[i]);
	    auto f2 = m2.find(v2[i]);
	    if (f1 == m1.end() && f2 == m2.end()) {
		m1.insert({v1[i], v2[i]});
		m2.insert({v2[i], v1[i]});
	    } else if (f1 != m1.end() && f2 != m2.end()) {
		if (f1->second != v2[i] || f2->second != v1[i]) 
		    return false;
	    } else return false;
	}

	return true;
    }
};