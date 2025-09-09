// 120. Triangle
// https://leetcode.com/problems/triangle/
// Question - Given a triangle array, return the minimum path sum from top to bottom. For each step, you may move to an adjacent number on the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1]; // start from last row

        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
