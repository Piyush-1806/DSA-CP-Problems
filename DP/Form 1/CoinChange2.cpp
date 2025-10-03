// Question - Coin Change II
// URL: https://leetcode.com/problems/coin-change-2/
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int rec(int idx, int amount, vector<int>& coins){
        // base case
        if(amount == 0) return 1;
        if(idx == n) return 0;

        // cache check
        if(dp[idx][amount] != -1) return dp[idx][amount];

        // transition
        int ans = 0;
        // take coin[idx] if possible
        if(amount - coins[idx] >= 0){
            ans += rec(idx, amount - coins[idx], coins); // stay at idx (unlimited supply)
        }
        // skip coin[idx]
        ans += rec(idx + 1, amount, coins);

        // save and return
        return dp[idx][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp = vector<vector<int>>(n+1, vector<int>(amount+1, -1));
        return rec(0, amount, coins);
    }
};
