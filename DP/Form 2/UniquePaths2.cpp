// UniquePaths2.cpp
// Question link: https://leetcode.com/problems/unique-paths-ii/
// Question: A robot is located at the top-left corner of a m x n grid (m rows, n columns). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. How many possible unique paths are there, given that some cells in the grid are obstacles? 
// Note: The answer is guaranteed to be less than or equal to 2 * 10^9.

class Solution {
public:
    const int MOD = 2e9;
    vector<vector<int>>dp;

    int rec(int m, int n,vector<vector<int>>& obstacleGrid){
        //pruning
        if(obstacleGrid[m][n]==1) return 0;
        //base case
        if(m==0 && n==0) return 1;
        //cache check
        if(dp[m][n]!=-1) return dp[m][n];
        //transition
        int ans = 0;
        if(m>0 && n>0) ans = (rec(m-1,n,obstacleGrid))%MOD + (rec(m,n-1,obstacleGrid))%MOD;
        else if(m==0) ans = (rec(m,n-1,obstacleGrid))%MOD;
        else if (n==0) ans = (rec(m-1,n,obstacleGrid))%MOD;
        //save and return
        return dp[m][n] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        return rec(m-1,n-1,obstacleGrid);
    }
};