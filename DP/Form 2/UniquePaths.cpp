// UniquePaths.cpp
// Question link: https://leetcode.com/problems/unique-paths/
// Question: A robot is located at the top-left corner of a m x n grid (m rows, n columns). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. How many possible unique paths are there?
// Note: The answer is guaranteed to be less than or equal to 2 * 109.

class Solution {
public:

    vector<vector<int>> dp;
    const int MOD = 2e9;

    int rec(int m,int n) {
        //base case
        if(m==0 && n==0) return 1;
        //cache check
        if(dp[m][n]!=-1) return (dp[m][n])%MOD;
        //transition
        int ans = 0;
        if(m!=0) ans = (ans + rec(m-1,n)%MOD)%MOD;
        if(n!=0) ans = (ans + rec(m,n-1)%MOD)%MOD;
        //save and return
        return dp[m][n] = ans%MOD;
    }
    int uniquePaths(int m, int n) {
        dp = vector(m,vector<int>(n,-1));
        return rec(m-1,n-1);
    }
};