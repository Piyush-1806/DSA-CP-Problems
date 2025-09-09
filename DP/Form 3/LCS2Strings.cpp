// leetcode 1143
// https://leetcode.com/problems/longest-common-subsequence/
// question - Given two strings text1 and text2, return the length of their longest common subsequence.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// It can be proven that there is always a unique longest common subsequence.
// If there is no common subsequence, return 0.

class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i, int j, string& s1, string& s2){
        int x = s1.size();
        int y = s2.size();
        //pruning
        if(i==x || j==y) return 0;
        //base case-> not required here
        //cache check
        if(dp[i][j]!=-1) return dp[i][j];
        //transitions
        int ans = 0;
        ans = max(rec(i+1,j,s1,s2),rec(i,j+1,s1,s2));
        if(s1[i]==s2[j]){
            ans = max(ans,(1+rec(i+1,j+1,s1,s2)));
        }
        //save and return
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        dp = vector<vector<int>>(s1,vector<int>(s2,-1));
        return rec(0,0,text1,text2);
    }
};