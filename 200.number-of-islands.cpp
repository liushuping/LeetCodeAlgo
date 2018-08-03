/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (37.52%)
 * Total Accepted:    198.9K
 * Total Submissions: 530.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 * 
 */
#define water '0'
#define island '1'

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count(0);
        
        for (int row(0); row < grid.size(); ++row) {
            for (int col(0); col < grid[0].size(); ++col) {
                if (grid[row][col] == island) {
                    ++count;
                    waterfy(grid, row, col);
                }
            }
        }
        
        return count;
    }
    
    void waterfy(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || col < 0) return;
        if (row >= grid.size()) return;
        if (col >= grid[0].size()) return;
        if (grid[row][col] == water) return;
        
        grid[row][col] = water;
        waterfy(grid, row - 1, col);
        waterfy(grid, row + 1, col);
        waterfy(grid, row, col - 1);
        waterfy(grid, row, col + 1);
    }
};