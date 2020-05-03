/* https://leetcode.com/problems/minimum-path-sum/
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid.empty()) return 0;
        
        vector<vector<int>>v(m, vector<int>(n)); //m columns and n rows.
        
        v[0][0] = grid[0][0];
        
        for (int i = 1; i < m; i++)
            v[i][0] = v[i-1][0] + grid[i][0];
        
        for (int j = 1; j < n; j++)
            v[0][j] = v[0][j-1] + grid[0][j];
        
        for (int i = 1; i < m; i++) 
        {
            for (int j = 1; j < n; j++) 
            {
                v[i][j] = min(v[i][j-1], v[i-1][j]) + grid[i][j];
            }
        }
        
        return v[m-1][n-1];
    }
};
