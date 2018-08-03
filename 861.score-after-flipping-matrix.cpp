/*
 * [891] Score After Flipping Matrix
 *
 * https://leetcode.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (69.13%)
 * Total Accepted:    3.8K
 * Total Submissions: 5.5K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 * 
 * 
 */
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        int res = row * (1 << (col - 1));
        for (int i = 1; i < col; ++i) {
            int sum = 0;
            for (int j = 0; j < row; ++j) {
                if (A[j][0]) sum += A[j][i];
                else sum += 1 - A[j][i];
            }
            
            sum = sum > row - sum ? sum : row - sum;
            res += sum * (1 << (col - 1 - i));
        }
        
        return res;
    }
};