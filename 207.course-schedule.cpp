/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (34.47%)
 * Total Accepted:    137.9K
 * Total Submissions: 400.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& p) {
        if (p.size() == 0) return true;

        int count(0);
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> graph;
        vector<int> zeros;

        for (int i(0); i < p.size(); ++i) {
            degree[p[i].first]++;
            graph[p[i].second].push_back(p[i].first);
        }

        for (int i(0); i < n; ++i)
            if (degree[i] == 0) zeros.push_back(i);

        if (zeros.size() == 0) return false;
        while(zeros.size() > 0) {
            auto vec = graph[zeros.back()];
            zeros.pop_back();
            count++;
            for (int i(0); i < vec.size(); ++i) {
                int v(vec[i]);
                if (--degree[v] == 0) zeros.push_back(v);
            }
        }

        return count == n;
    }
};