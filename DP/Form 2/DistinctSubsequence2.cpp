// DistinctSubsequence2.cpp
// Question link: https://leetcode.com/problems/distinct-subsequences-ii/
//Question: Given a string s, return the number of distinct non-empty subsequences of s modulo 10^9 + 7.

class Solution {
public:
    vector<int> dp;
    vector<int> lastOccurence;
    int MOD = 1e9+7;

    int rec(int i, string &s) {
        // base case
        if (i == 0) return 1;
        // cache check
        if (dp[i] != -1) return dp[i];
        //transition & save and return
        dp[i] = (2LL * rec(i-1, s)) % MOD;
        if (lastOccurence[c] != -1) {
            dp[i] = (dp[i] - rec(lastOccurence[c]-1, s) + MOD) % MOD;
        }
        lastOccurence[c] = i;
        return dp[i];
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        dp = vector<int>(n+1, -1);
        lastOccurence = vector<int>(26, -1);
        int ans = rec(n, s);
        return (ans - 1 + MOD) % MOD;
    }
};

