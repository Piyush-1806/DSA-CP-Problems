// UniquePaths.cpp
 // Question link: https://leetcode.com/problems/unique-paths/
  // Question: A robot is located at the top-left corner of a m x n grid (m rows, n columns). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. How many possible unique paths are there?
// Note: The answer is guaranteed to be less than or equal to 2 * 109.

class Solution {
public:
    vector<vector<int>> dp;
    int rec(int m, int n, vector<vector<int>>& grid){
        //base case
        if(m==0 && n==0) return grid[0][0];
        //cache check
        if(dp[m][n]!=-1) return dp[m][n];
        //transition
        int ans = grid[m][n];
        if (m>0 && n>0) ans += min(rec(m-1,n,grid),rec(m,n-1,grid));
        else if (m==0) ans += rec(m,n-1,grid);
        else if (n==0) ans += rec(m-1,n,grid);
        //save and return
        return dp[m][n] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n,-1));
        return rec(m-1,n-1,grid);
    }
};
