// LeetCode Problem: Climbing Stairs
// Problem Link: https://leetcode.com/problems/climbing-stairs/ 
// Approach: Top-Down Dynamic Programming with Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dp;
    int rec(int level) {
        int n = dp.size() - 1; 
        //pruning
        if (level > n)   return 0;
        //base case
        if (level == n)  return 1;
        //caching
        if (dp[level] != -1) return dp[level];
        //transition
        int ans = 0;
        for(int steps = 1;steps<=2; steps++){
            int ways = rec(level+steps);
            ans+=ways;
        }

        dp[level] = ans;
        return ans;
    }

    int climbStairs(int n) {
        dp = vector<int>(n + 1, -1);  
        return rec(0);
    }
};
