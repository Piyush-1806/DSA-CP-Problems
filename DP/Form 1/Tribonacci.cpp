// LeetCode Problem: Tribonacci Number
// Problem Link: https://leetcode.com/problems/tribonacci-number/
// Approach: Top-Down Dynamic Programming with Memoization
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
vector<int> dp;

    int rec(int n){
        //base case
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        //cache check
        if(dp[n]!=-1) return dp[n];
        //transition
        int ans = 0;
        ans += rec(n-1) + rec(n-2) + rec(n-3);
        //save and return
        dp[n] = ans;
        return ans;
    }

    int tribonacci(int n) {
        dp = vector<int>(n+1,-1);
        return rec(n);
    }
};