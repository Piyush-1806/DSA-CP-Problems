// LeetCode Problem: Min Cost Climbing Stairs
// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Approach: Top-Down Dynamic Programming with Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dp;

    int rec( int level, vector<int>& cost){
        int n = cost.size();
        //base case
        if(level >= n) return 0;
        //cache check
        if(dp[level]!=-1) return dp[level];
        //transition
        int ans = cost[level] + min(rec(level+1,cost),rec(level+2,cost));
        //save and return
        dp[level] = ans;
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp = vector<int>(n+1,-1);
        return min(rec(0,cost),rec(1,cost));
    }
};