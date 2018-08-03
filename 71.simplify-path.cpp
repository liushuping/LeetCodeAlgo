/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.78%)
 * Total Accepted:    120.5K
 * Total Submissions: 449.7K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * Corner Cases:
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public: 
    string simplifyPath(string path) {
        char c;
        string op;
        int last = 0;
        vector<int> vec(200, 0);

        path += "/";

        for (int i = 1; i < path.size(); ++i) {
            c = path[i];
            path[++last] = c;

            if (c == '.') op += c;

            if (c != '.' && c != '/') op.clear();

            if (c == '/') {
                if (op == "..") vec.pop_back();

                if (path[last - 1] != '/' && op != "." && op != "..") vec.push_back(last);
                    
                last = vec.back();
                op.clear();
            }
        }

        if (last == 0) return "/";
        if (path[last] == '/') return path.substr(0, last);
        return path.substr(0, last + 1);
    }
};