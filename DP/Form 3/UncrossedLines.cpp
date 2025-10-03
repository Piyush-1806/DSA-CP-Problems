// Question - Uncrossed Lines
// URL: https://leetcode.com/problems/uncrossed-lines/
// You are given two integer arrays nums1 and nums2. We write the integers of numss1 and nums2 (in the order they are given) on two separate horizontal lines.
// We want to draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
// Return the maximum number of connecting lines we can draw in this way.


class Solution {
public:
    vector<vector<int>> dp;
    int rec(int x, int y, vector<int>& nums1, vector<int>& nums2){
        //pruning
        if(x<0 || y<0) return 0;
        //basecase - not required
        //cache check
        if(dp[x][y]!=-1) return dp[x][y];
        //transition
        int ans;
        ans = max(rec(x,y-1,nums1,nums2), rec(x-1,y,nums1,nums2));
        if(nums1[x]==nums2[y]){
            ans = max(ans, 1+rec(x-1,y-1,nums1,nums2));
        }

        //save and return
        return dp[x][y] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        dp = vector<vector<int>>(n1,vector<int>(n2,-1));
        int ans = rec(n1-1,n2-1,nums1,nums2);
        return ans;
    }
};