// LeetCode Problem: Longest Increasing Subsequence
// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
// Approach: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)   

class Solution {
    public:
        vector<int> dp;
        int rec(int i, vector<int>&nums){
            int n = nums.size();
            //pruning
            if(i<0) return 0;
            //no base case required
            //cache check
            if(dp[i]!=-1) return dp[i];
            //transition
            int ans = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    ans = max(ans,1+rec(j,nums));
                }
            }
            //save and return
            return dp[i] = ans;
        }
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp = vector<int> (n,-1);
            int ans = 0;
            for(int i=0; i<n; i++){
                ans = max(ans,rec(i,nums));
            }
            return ans;
        }
    };