// Question - Minimum Insertion Steps to Make a String Palindrome
// URL: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int rec(int i, int j, string& s){
        //pruning
        if(i>=j) return 0;
        //base case - not required
        //cache check
        if(dp[i][j]!=-1) return dp[i][j];
        //transition
        int ans;
        if(s[i]==s[j]){
            ans = rec(i+1,j-1,s);
        }
        else{
            ans = 1 + min(rec(i+1,j,s),rec(i,j-1,s));
        }
        //save and return
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n,-1));
        int ans = rec(0,n-1,s);
        return ans;
    }
};