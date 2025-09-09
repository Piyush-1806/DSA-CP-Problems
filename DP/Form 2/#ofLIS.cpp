// LeetCode Problem: Number of Longest Increasing Subsequences
// Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequences/
// Approach: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
    public:
        vector<int> dp, cnt;
    
        int rec(int i, vector<int>& nums){
            //pruning
            if(i < 0) return 0;
            //cache check
            if(dp[i] != -1) return dp[i];
            //transition
            int bestLen = 1;
            int ways = 1; // at least one subsequence (the element itself)
    
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    int prevLen = rec(j, nums);
                    if(prevLen + 1 > bestLen){
                        bestLen = prevLen + 1;
                        ways = cnt[j];  // reset ways to those of j
                    }
                    else if(prevLen + 1 == bestLen){
                        ways += cnt[j]; // add more ways
                    }
                }
            }
            //save ad return
            dp[i] = bestLen;
            cnt[i] = ways;
            return dp[i];
        }
    
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp = vector<int>(n, -1);
            cnt = vector<int>(n, 0);
    
            int maxLen = 0;
            int ans = 0;
    
            for(int i = 0; i < n; i++){
                int length = rec(i, nums);
                if(length > maxLen){
                    maxLen = length;
                    ans = cnt[i];  // reset count
                }
                else if(length == maxLen){
                    ans += cnt[i]; // add more ways
                }
            }
            return ans;
        }
    };
    