// LeetCode Problem: Delete and Earn
// Problem Link: https://leetcode.com/problems/delete-and-earn/
// Approach: Dynamic Programming
// Time Complexity: O(n + m) where n is the number of elements in nums and m is the maximum value in nums.
// Space Complexity: O(m) for the points array and O(m) for the dp array.   


/*
Instead of thinking in terms of deleting from the array directly, think in terms of value frequency.

Step 1: Count contributions
If you pick all xs in the array: You earn x * count[x] points.
But you can’t take (x-1) and (x+1) anymore.

So the problem reduces to: Given an array points[] where points[x] = x * frequency[x], choose a subset such that no two adjacent indices are both chosen.

Step 2: Relation to House Robber
This is exactly the House Robber DP:
If you take value x, you must skip x-1.
If you skip value x, you may take x-1.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // frequency to points array
        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }
        
        // dp[i] = max points considering numbers up to i
        vector<int> dp(maxVal + 1, 0);
        dp[0] = 0;
        dp[1] = points[1];
        
        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }
        
        return dp[maxVal];
    }
};