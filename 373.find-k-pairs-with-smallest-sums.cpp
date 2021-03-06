/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.68%)
 * Total Accepted:    45.7K
 * Total Submissions: 144.2K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k. 
 * 
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * 
 * Example 1:
 * 
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 * 
 * Return: [1,2],[1,4],[1,6]
 * 
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 * 
 * Return: [1,1],[1,1]
 * 
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * Given nums1 = [1,2], nums2 = [3],  k = 3 
 * 
 * Return: [1,3],[2,3]
 * 
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */
#define el pair<int, pair<int, int>>

struct cmp{
  bool operator()(el a, el b){
    return a.first > b.first;
  }
};

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<el, vector<el>, cmp> minQ;
        vector<pair<int, int>> vec;
        
        if (nums1.empty() || nums2.empty())
            return vec;
        
        int i = 0, j = 0;
        minQ.push(make_pair(nums1[i] + nums2[j], make_pair(i, j)));
        
        while (k-- && !minQ.empty()) {
            auto p = minQ.top();
            minQ.pop();
            auto p1 = p.second;
            vec.push_back(make_pair(nums1[p1.first], nums2[p1.second]));
            if (p1.second + 1 < nums2.size())
                minQ.push(make_pair(nums1[p1.first] + nums2[p1.second + 1], make_pair(p1.first, p1.second + 1)));
            if (p1.second == 0 && p1.first + 1 < nums1.size())
                minQ.push(make_pair(nums1[p1.first + 1] + nums2[p1.second], make_pair(p1.first + 1, p1.second)));
        }
        
        return vec;
    }
};