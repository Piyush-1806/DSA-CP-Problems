// Problem: Longest Arithmetic Subsequence of Given Difference
// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/  
// Question - Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

class Solution {
public:
    vector<int> dp;
    unordered_map<int,int> best;  // value -> best subsequence length ending at that value

    int rec(int i, vector<int>& arr, int difference){
        // cache check
        if(dp[i] != -1) return dp[i];

        int ans = 1; // every element alone is length 1

        // instead of looping j<i, directly check if arr[i]-difference exists
        if(best.count(arr[i] - difference)) {
            ans = max(ans, 1 + best[arr[i] - difference]);
        }

        return dp[i] = ans;
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        dp = vector<int>(n, -1);
        best.clear();

        int ans = 0;
        for(int i=0; i<n; i++){
            int cur = rec(i, arr, difference);
            best[arr[i]] = cur;   // update best subsequence ending at arr[i]
            ans = max(ans, cur);
        }
        return ans;
    }
};
