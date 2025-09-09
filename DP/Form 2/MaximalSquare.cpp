// Problem: Maximal Square
// Link: https://leetcode.com/problems/maximal-square/
// Question - Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

class Solution {
public:
    vector<vector<int>> dp;

    int rec(int i, int j, vector<vector<char>>& matrix){
        // boundary check
        if(i < 0 || j < 0) return 0;
        // cache check
        if(dp[i][j] != -1) return dp[i][j];
        // base case for first row/col
        if(i == 0 || j == 0) return dp[i][j] = (matrix[i][j] == '1' ? 1 : 0);
        // if cell is '0'
        if(matrix[i][j] == '0') return dp[i][j] = 0;

        // transition
        return dp[i][j] = 1 + min({rec(i-1,j,matrix), rec(i,j-1,matrix), rec(i-1,j-1,matrix)});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, rec(i,j,matrix));
            }
        }
        return ans * ans;  // area of largest square
    }
};