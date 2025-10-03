// Question - Perfect Squares
// URL: https://leetcode.com/problems/perfect-squares/
// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

class Solution {
public:
    vector<int>arr;
    vector<vector<int>>dp;
    int rec(int idx, int sum_left){
        //pruning
        if(sum_left<0) return 1e9+7;
        //base case
        if(sum_left == 0) return 0;
        //cache check
        if(dp[idx][sum_left]!= -1) return dp[idx][sum_left];
        //transition
        int ans = 1e9+7;
        if(arr[idx]<=sum_left && idx-1>=0){
            ans = min(1+rec(idx, sum_left-arr[idx]), rec(idx-1,sum_left));
        }
        else{
            if(idx-1>=0){
                ans = rec(idx-1,sum_left);
            }
        }
        //save and return
        return dp[idx][sum_left] = ans;
    }
    int numSquares(int n) {
        int i = 0;
        while(i*i<=n){
            arr.push_back(i*i);
            i++;
        }
        int size = arr.size();
        dp = vector<vector<int>> (size, vector<int>(n+1,-1));
        int ans = rec(size-1, n);
        return ans;
    }
};